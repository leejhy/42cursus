from django.db import models
from home.models import User
# Create your models here.

class Login(models.Model):
	#nick_id로 저장됨
	nick = models.OneToOneField(User, on_delete=models.CASCADE,primary_key=True)
	is_seoul = models.BooleanField(default=False)
	email_code = models.CharField(max_length=6, default='')

# # 각 관계 필드에는 on_delete 옵션이 있습니다. 이는 관련된 객체가 삭제될 때 어떻게 처리할지 지정하는 옵션입니다. 예를 들어, on_delete=models.CASCADE는 관련 객체가 삭제되면 해당 객체도 함께 삭제됩니다.
# # related_name은 역방향 관계에서 사용할 수 있는 이름을 지정합니다. 예를 들어, User 모델에서 posts를 통해 해당 사용자의 게시물 목록에 접근할 수 있습니다.
# 이와 같이 Django의 관계 필드를 사용하면 데이터베이스 테이블 간의 관계를 쉽게 정의할 수 있습니다.