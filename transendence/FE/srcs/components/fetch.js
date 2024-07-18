import { navigateTo } from "../components/router";
import { OAUTH_REDIRECT_URL } from "./state";

export async function checkJwt() {
  console.log("checkJwt", sessionStorage.getItem("jwt"));
  const response = await fetch(process.env.USER_VERIFY_URL, {
    method: "GET",
    headers: {
      "Content-Type": "application/json",
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
  });
  if (response.ok) {
    console.log("response ok", response);
    return true;
  } else {
    return false;
  }
}

export function verifyTwoFA() {
  const twoFAValue = document.getElementById("twofa-input")?.value ?? null;
  fetch(process.env.TWO_FA_VERIFY_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "Authorization": `${sessionStorage.getItem("jwt")}`,
    },
    body: JSON.stringify(twoFAValue),
  })
    .then((res) => {
      console.log("res", res);
      if (res.ok){
        res.json().then((data) => {
          console.log("success verify twofa data", data);
          if (sessionStorage.getItem("jwt")) {
            sessionStorage.removeItem("jwt");
          }
          sessionStorage.setItem("jwt", data.jwt);
          sessionStorage.setItem("login", true);
          navigateTo("/main");
        })
      }
      else {
        console.log("verify fail");
      }})
}


// export function verifyTwoFA() {
//   const twoFAValue = document.getElementById("twofa-input")?.value ?? null;
//   fetch(process.env.TWO_FA_VERIFY_URL, {
//     method: "POST",
//     headers: {
//       "Content-Type": "application/json",
//       credentials: 'include',
//       Authorization: `${sessionStorage.getItem("jwt")}`,
//     },
//     body: JSON.stringify(twoFAValue),
//   })
//     .then((res) => {
//       console.log("res", res);
//       if (res.ok) {
//         res.json().then((data) => {
//         // console.log("success verify twofa");
//         console.log("success verify twofa data", data);
//         if (sessionStorage.getItem("jwt"))
//           sessionStorage.removeItem("jwt")
//         sessionStorage.setItem("jwt", res.data);
          
//         // sessionStorage.getItem("login", true);
//         navigateTo("/main");
//         }) })
// .catch((error) => {});
// }



export function createTwoFA() {
  const jwt = { jwt: sessionStorage.getItem("jwt") };
  if (!jwt.jwt) {
    alert("토큰이 없습니다.");
    navigateTo("/main");
    return;
  }
  fetch(process.env.TWO_FA_CREATE_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      credentials: 'include',
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
  })
    .then((res) => {
      if (res.ok) {
        console.log("success create twoFA", res);
      } else {
        console.log("FAIL create twoFA", res);
      }
    })
    .catch((error) => {
      console.log("error", error);
    });
}

console.log("OAUTH_REDIRECT_URL", OAUTH_REDIRECT_URL);

export function setLogIn() {
  window.location.href = OAUTH_REDIRECT_URL;
}

export function setLogOut() {
  sessionStorage.removeItem("jwt");
  sessionStorage.removeItem("login");
  alert("logout 되었습니다");
  navigateTo("/main");
}

export function handleOAuthRedirect() {
  const url = window.location.href;
  if (!url.includes("code=")) return;
  const accessToken = url.split("code=")[1];

  fetch("https://127.0.0.1/login/", {
    method: "POST",
    headers: { "Content-Type": "application/json", credentials: 'include'},
    body: JSON.stringify({
      code: accessToken,
    }),
  }).then((res) => {
    console.log("res", res);
    if (res.ok) {
      console.log("response, ", res);
      res.json().then((data) => {
        console.log("data", data);
        sessionStorage.setItem("jwt", data.jwt);
        if (data.jwt) {
          navigateTo("/twofactor");
        } else {
          navigateTo("/main");
        }
      });
    } else {
      alert("로그인에 실패했습니다.");
      navigateTo("/main");
    }
  });
}

export async function DiceStat() {
  try {
    const response = await fetch(process.env.DICE_STAT_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    console.log("dice stat response", response);
    if (response.ok) {
      console.log("success dice stat");
      return await response.json(); // 성공 시 데이터 반환
    } else {
      console.log("fail dice stat");
      throw new Error("Failed to fetch dice stat");
    }
  } catch (error) {
    console.error("Error in DiceStat:", error);
    throw error; // 에러를 다시 던져서 호출자가 처리할 수 있게 함
  }
}

export function DiceResult(data) {
  fetch(process.env.DICE_RESULT_URL, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      Authorization: `${sessionStorage.getItem("jwt")}`,
    },
    body: JSON.stringify({
      data: data,
    }),
  })
    .then((res) => {
      if (res.ok) {
        console.log("dice result success");
      } else {
        console.log("dice result fail");
      }
    })
    .catch((error) => {});
}

// profile
export async function ProfileDelete() {
  try {
    const res = await fetch(process.env.USER_INFO_DEL_URL, {
      method: "DELETE",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (res.ok) {
      sessionStorage.removeItem("jwt");
      sessionStorage.removeItem("login");
      console.log("profile delete success");
      return true;
    } else {
      console.log("profile delete fail");
      return false;
    }
  } catch (error) {
    console.log("error", error);
    return false;
  }
}

export async function ProfileAnony() {
  try {
    const res = await fetch(process.env.USER_INFO_ANONY_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (res.ok) {
      console.log("profile anony success");
      return true;
    } else {
      console.log("profile anony fail");
      return false;
    }
  } catch (error) {
    console.log("error", error);
    return false;
  }
}

export const ProfileGetData = async () => {
	console.log("process.env.USER_INFO_URL",process.env.USER_INFO_URL)
	try {
    const response = await fetch(process.env.USER_INFO_URL, {
      method: "GET",
      headers: {
        "Content-Type": "application/json",
        Authorization: `${sessionStorage.getItem("jwt")}`,
      },
    });
    if (response.ok) {
      console.log("success profile get data", response);
      return response.json(); // 성공 시 데이터 반환
    } else {
      throw new Error("Failed to fetch user info");
    }
  } catch (error) {
    console.log("Error in ProfileGetData:", error);
    throw error;
  }
};

// export async function DiceResult(data) {
//   try {
//     const response = await fetch(process.env.DICE_RESULT_URL, {
//       method: "POST",
//       headers: {
//         "Content-Type": "application/json",
//         Authorization: `${sessionStorage.getItem("jwt")}`,
//       },
//       body: JSON.stringify({
//         code: data,
//       }),
//     });
//     // console.log("dice stat response", response);
//     if (response.ok) {
//       console.log("success dice  result stat");
//       return await response.json(); // 성공 시 데이터 반환
//     } else {
//       console.log("fail dice  result stat");
//       throw new Error("Failed to fetch dice stat");
//     }
//   } catch (error) {
//     console.error("Error in DiceStat:", error);
//     throw error; // 에러를 다시 던져서 호출자가 처리할 수 있게 함
//   }
// }

// export function DiceStat() {
//   fetch(process.env.DICE_STAT_URL, {
//     method: "GET",
//     headers: {
//       "Content-Type": "application/json",
//       Authorization: `${sessionStorage.getItem("jwt")}`,
//     },
//     // mode : "no-cors",
//     body: JSON.stringify(twoFAValue),
//   })
//     .then((res) => {
//       if (res.ok) {
//         console.log("success dice stat");
//         // navigateTo("/main");
//         // history.pushState(null, null, "/main");
//         // $appElement.innerHTML = "";
//         // router();
//       } else {
//         console.log("fail dice stat");
//         // history.pushState(null, null, "/login");
//         // $appElement.innerHTML = "";
//         // router();
//       }
//     })
//     .catch((error) => {});
// }
