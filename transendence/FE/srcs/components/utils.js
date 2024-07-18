import { checkJwt } from "./fetch";

export const isValidPlayerNames = (playerNames) => {
  // 배열이 아닌 경우 false 반환
  if (!Array.isArray(playerNames)) {
    return false;
  }

  // 각 이름 검사
  for (const name of playerNames) {
    // 영어 문자열 검사
    const englishRegex = /^[a-zA-Z]+$/;
    if (!englishRegex.test(name)) {
      return false;
    }

    // 빈 문자열 검사
    if (name.trim() === "") {
      return false;
    }
  }

  return true;
};

// route path 정규화 -> / 제거
export const normalizePath = (path) =>
  path.endsWith("/") ? path.slice(0, -1) : path;

// 브라우저 주소창의 path를 정규식으로 변환
export const pathToRegex = (path) =>
  new RegExp("^" + path.replace(/\//g, "\\/").replace(/:\w+/g, "(.+)") + "$");

// 동적 라우팅에서 params 추출
export const getParams = (match) => {
  const values = match.result.slice(1);
  const keys = Array.from(match.route.path.matchAll(/:(\w+)/g)).map(
    (result) => result[1]
  );
  return Object.fromEntries(keys.map((key, i) => [key, values[i]]));
};

export const setGameHeaderDisabled = (path) => {
  const header = document.getElementById("header");
  const footer = document.getElementById("footer");
  if (path === "/pong/game" || path === "/dice/game") {
    header.classList.add("game-disable");
    footer.classList.add("game-disable");
  } else {
    header.classList.remove("game-disable");
    footer.classList.remove("game-disable");
  }
};


// export const  changeLoginButtonText = async () =>{
//   const LoginButton = document.getElementById("login_button");
//   // jwt 가지고 있는지 유저 판단
//   // const isJwt = await checkJwt();
//   console.log("change jwt login", isJwt);
//   if (isJwt) LoginButton.textContent = "42 logout";
//   else {
//     if (location.pathname === "/main" || location.pathname==="/twofactor")
//       navigateTo();
//     LoginButton.textContent = "42 login";
//   }
// }


export const checkLoginToken = async () => {
  const LoginButton = document.getElementById("login");
  const LogoutButton = document.getElementById("logout");
  if (sessionStorage.getItem("login")){
    LoginButton.classList.add("disabled");
    LogoutButton.classList.remove("disabled");
    LoginButton.textContent = "42 logout";
  }else {
    LoginButton.classList.remove("disabled");
    LogoutButton.classList.add("disabled");
    LoginButton.textContent = "42 login";
  }
}
