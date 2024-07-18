import { navigateTo, router } from "./router";
import { players, pongGameMode, setPongGameMode, resetPlayers } from "./state";
import { isValidPlayerNames, normalizePath } from "./utils";
import { ProfileAnony as ProfileAnony, ProfileDelete, setLogIn, verifyTwoFA } from "./fetch";
import { changeLanguage } from "./language";

export const clickMainTitle = () => {
  navigateTo("/main");
};

export const clickProfilePage = () => {
  navigateTo("/profile");
};

export const clickGameStart = (id) => {
  resetPlayers();
  const playerNameInputs = document.querySelectorAll(".player_name");
  playerNameInputs.forEach((input, index) => {
    players[index] = input.value;
  });
  console.log("game starting players", players);
  // TODO: alert 메시지 언어별로 바꾸기?
  // alert도 언어가 바뀔때 바뀌어야 하나?
  if (isValidPlayerNames(players) === false) {
    alert("영어로 입력하고 빈 문자열은 안됩니다");
    return;
  }

  if (id === "pong") navigateTo("/pong/game");
  else if (id === "dice") navigateTo("/dice/game");
};

export function clickPongMode(id) {
  const [mode, players] = id.split("_");
  //   console.log(mode);
  let navigateToUrl;

  if (mode == "") {
    switch (players) {
      case "two":
        navigateToUrl = "/dice/room/2";
        break;
      case "four":
        navigateToUrl = "/dice/room/4";
        break;
      default:
        console.error("Invalid players value:", players);
        return;
    }
  } else {
    switch (players) {
      case "two":
        navigateToUrl = "/pong/room/2";
        break;
      case "four":
        navigateToUrl = "/pong/room/4";
        break;
      default:
        // 예상치 못한 값이 들어온 경우 처리
        console.error("Invalid players value:", players);
        return;
    }
  }
  setPongGameMode(mode);
  console.log("mode", mode);
  navigateTo(navigateToUrl);
}

export function clickGameMode(id) {
  if (id === "pong") navigateTo("/pong");
  else if (id === "dice") navigateTo("/dice");
}

export function onClickLoginButton() {
  setLogIn();
  // OAUTH 로그인 하기
  // alert("oauth 로그인");
  // navigateTo("/pong/room");
}

export const clickChangeLanguage = (id) => {
  // 예외처리
  if (
    normalizePath(location.pathname) === "/twofactor" ||
    normalizePath(location.pathname) === "/dice/game" ||
    normalizePath(location.pathname) === "/pong/game"
  ) {
    return;
  }

  const languageButtons = document.querySelectorAll(".btn-check");
  console.log("id", id);
  changeLanguage(id);

  languageButtons.forEach((button) => {
    if (button.id === id) {
      button.checked = true;
    } else {
      button.checked = false;
    }
  });
  router();
};

export const onClickStatistics = () => {
  navigateTo("/statistics");
  // try {
  //   // NOTE : BE에 정보 요청
  //   const statData = await DiceStat();
  //   console.log("Received stat data:", statData);
  // } catch (error) {
  //   console.error("Error fetching dice statistics:", error);
  //   // 에러 처리 (예: 사용자에게 오류 메시지 표시)
  // }
};

export const onClickTwoFA = () => {
  verifyTwoFA();
};

export async function clickProfileButton(id) {
  console.log("id", id);

  if ("user-del" === id) {
    const isDeleted = await ProfileDelete();
    console.log("isDeleted", isDeleted);
    alert("user가 삭제되었습니다");
    navigateTo("/main");
  } else if ("user-anony" === id) {
    const isAnony = await ProfileAnony();
    console.log("isAnony", isAnony);
    if (isAnony) {
      // navigateTo("/profile");
      router("/profile");
    } else {
      navigateTo("/main");
    }
  }
}
