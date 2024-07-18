from django.shortcuts import render, redirect
from django.http import HttpResponse, HttpResponseRedirect, HttpResponseBadRequest, JsonResponse
from django.core.mail import EmailMessage
from .models import User, Login
import string, random, datetime, json
import requests, jwt
import os
# Create your views here.

def apiTokenRequest(access_token):
    headers = {'Authorization' : 'Bearer ' + access_token}
    data = requests.get(os.environ.get('API_USER_INFO_URL'), headers=headers)
    return data

def getTokenInfo(access_token):
    headers = {'Authorization' : 'Bearer ' + access_token}
    get_info = requests.get(os.environ.get('API_TOKEN_INFO'), headers=headers)
    return get_info

def isValidToken(jwt_token) :
    try:
        jwttoken = jwt.decode(jwt_token, os.environ.get('SECRET_KEY'), algorithms=os.environ.get('ALGORITHM'))
        access_token = jwttoken['access_token']
        nick = jwttoken['user_nick']
        if not nick or not Login.objects.filter(nick=nick).exists():
            return None
        if jwttoken['is_email'] != "true":
            return None
        get_info = getTokenInfo(access_token)
        expires_time = get_info.json().get('expires_in_seconds')
        if expires_time is None or int(expires_time) <= 2:
            return None
        return nick
    except Exception:
        return None

def storeInfo(email, nick, name):
    print('email', email)
    print('nick', nick)
    print('name', name)
    if User.objects.filter(nick=nick).exists() is True:
        return
    User.objects.create(email=email, nick=nick, name=name)
    if User.objects.filter(nick=nick).exists() is False :
        return HttpResponseBadRequest('400 user not found')
    Login.objects.create(nick = User.objects.get(nick=nick))

# TODO 이거 환경변수화 
def getAccessToken(code):
    url = os.environ.get('API_ACCESS_TOKEN_URL')
    data = {
        'grant_type': 'authorization_code',
        'client_id': os.environ.get('API_CLIENT_ID'),
        'client_secret': os.environ.get('API_CLIENT_SECRET'),
        'code': code,
        'redirect_uri': os.environ.get('API_REDIRECT_URI'),
        'scope':'public'
    }
    try :
        response = requests.post(url, data=data)
        access_token = response.json().get('access_token')
    except Exception:
        if access_token is None:
            print('access_token 400 ', access_token)
            return HttpResponseBadRequest('400 bad request')
    print('access token : ', access_token)
    if access_token is None:
        return HttpResponseBadRequest('400 bad request')
    get_user = apiTokenRequest(access_token)
    email = get_user.json().get('email')#email
    nick = get_user.json().get('login')#nick
    name = get_user.json().get('usual_full_name')#name
    storeInfo(email, nick, name)
    try :
        get_city = get_user.json().get('campus')[0]['city']
        if (get_city != "Seoul"):
            return HttpResponseBadRequest('400 bad request')
        if Login.objects.filter(nick=nick).exists() is False :
            return HttpResponseBadRequest('400 user not found')
        login = Login.objects.get(nick=nick)
        login.is_seoul = True
        login.save()
    except Exception:
        return HttpResponseBadRequest('400 bad request')
    return access_token

def makeJwtToken(access_token):
    get_user = apiTokenRequest(access_token)
    nick = get_user.json().get('login')
    if Login.objects.filter(nick=nick).exists() is False :
        return HttpResponseBadRequest('400 user not found')
    login = Login.objects.get(nick=nick)
    if login.is_seoul is False:
        return HttpResponseBadRequest('400 user not in seoul')
    payload = {
        'user_nick' : nick,
        'access_token' : access_token,
        'is_email' : "false",
        'exp' : datetime.datetime.now() + datetime.timedelta(days=1),
        'iat' : datetime.datetime.now()
	}
    try :
        token = jwt.encode(payload, os.environ.get('SECRET_KEY'), algorithm=os.environ.get('ALGORITHM'))
    except Exception :
        return None
    return token
    
def emailAuthString():
    len = 6
    numbers = string.digits
    auth_string = ""
    for i in range(len):
        auth_string += random.choice(numbers)
    return auth_string

def twofactor(request) :
    if request.method != 'POST':
        return HttpResponseRedirect('https://localhost/404/')
    cookie_jwt = request.headers.get('Authorization')
    print('def twofactor cookie_jwt : ', cookie_jwt)
    if cookie_jwt is None or cookie_jwt == '':
        return HttpResponseBadRequest('400 bad request')
    try :
        makejwttoken = jwt.decode(cookie_jwt, os.environ.get('SECRET_KEY'), algorithms=os.environ.get('ALGORITHM'))
    except Exception:
        return HttpResponseBadRequest('invalid token')
    access_token = makejwttoken['access_token']
    get_user = apiTokenRequest(access_token)
    if get_user is None :
        return HttpResponseBadRequest('400 bad request')
    email = get_user.json().get('email')
    nick = get_user.json().get('login')
    auth_string = emailAuthString()
    print("==========================")
    #email code 넣기
    if Login.objects.filter(nick=nick).exists() is False :
        return HttpResponseBadRequest('400 user not found')
    login = Login.objects.get(nick=nick)
    login.email_code = auth_string
    login.save()
    print("logincode : ",login.email_code)
    #email 발송부분

    subject = "Tssan 2fa mail"	# 타이틀
    to = [email]	# 수신할 이메일 주소
    # TODO 이메일 주소 환경변수화
    from_email = os.environ.get('EMAIL_LOGIN')
    message = auth_string + "\ntsssan 인증메일"	 # 본문

    try :
        EmailMessage(subject=subject, body=message, to=to, from_email=from_email).send()
    except Exception:
        return HttpResponseBadRequest('email send fail')
    return (HttpResponse(status=200))
        
def check(request) :
    if request.method != 'GET' :
        return HttpResponseRedirect('https://localhost/404/')
    cookie_jwt = request.headers.get('Authorization')
    if cookie_jwt is None :
        return HttpResponse('Unauthorized', status=401)
    ret = isValidToken(cookie_jwt)
    if ret:
        return HttpResponse('valid token', status=200)
    else :
        return HttpResponse('Unauthorized', status=401)
    
def emailAuth(request) : #테스트 해봐야함
    if request.method != 'POST':
        return HttpResponseRedirect('https://localhost/404/')
    cookie_jwt = request.headers.get('Authorization')
    print(cookie_jwt)
    if cookie_jwt is None :
        return HttpResponseBadRequest('400 def emailAuth, token fail')
    try :
        decoded_token = jwt.decode(cookie_jwt, os.environ.get('SECRET_KEY'), algorithms=os.environ.get('ALGORITHM'))
    except Exception:
        return HttpResponse('invalid token', status=400)
    nick = decoded_token['user_nick']
    if Login.objects.filter(nick=nick).exists() is False :
        return HttpResponseBadRequest('400 user not found')
    login = Login.objects.get(nick=nick)
    print('')
    email_code = request.body.decode().strip('"')
    print(email_code)
    if email_code == login.email_code and login.email_code != '':

        decoded_token['is_email'] = "true"
        try :
            new_token = jwt.encode(decoded_token, os.environ.get('SECRET_KEY'), algorithm=os.environ.get('ALGORITHM'))
        except Exception:
            print('new_token ::', new_token)
            return HttpResponseBadRequest('400 encode error')
        # login.is_email = True
        # login.save()
        return JsonResponse({'jwt':new_token})
    return HttpResponseBadRequest('400 email auth failed')

def index(request) :
    if request.method != 'POST':
        return HttpResponseRedirect('https://localhost/404/')
    try :
        data = json.loads(request.body)
        if 'code' not in data:
            return HttpResponseBadRequest('400 not in data')
    except Exception:
        return HttpResponseBadRequest('400 bad request')
    code = data['code']
    print('code', code)
    if code is None or code == '':
        return HttpResponseBadRequest('400 bad request')
    access_token = getAccessToken(code)
    if isinstance(access_token, HttpResponseBadRequest):
        return access_token
    jwt = makeJwtToken(access_token)
    print('2222222',jwt)
    if jwt is None:
        print("123232323132")
        return HttpResponseBadRequest('400 bad request')
    response = JsonResponse({'jwt':jwt})
    return response

# this attempt to set a cookie via a Set-Cookie header was blocked due to user preferences
# This Set-Cookie header didn't specify a "SameSite" attribute and was defaulted to
# "SameSite=Lax," and was blocked because it came from a cross-site response which was not the response to a top-level navigation.
# The Set-Cookie had to have been set with "SameSite=None" to enable cross-site usage