// 언어를 저장하는 변수 -> 나중에 cookie 로 받아오기

import {
  LanguageButtonHtml,
  MainTitleLanguageHtml,
  ProfileLanguageHtml,
} from "./languageHtml";
import { normalizePath } from "./utils";

// 백엔드에서 언어 저장안하면 프론트에서 세션에 저장
export let language = sessionStorage.getItem("language") || "en";

export function changeLanguage(lang) {
  sessionStorage.setItem("language", lang);
  language = lang;
}

// 나중에 click language부분이랑 바꾸기
// 막기 보다 지워버리는게 나을듯
export const setLanguage = (lang) => {
  if (
    normalizePath(location.pathname) === "/twofactor" ||
    normalizePath(location.pathname) === "/dice/game" ||
    normalizePath(location.pathname) === "/pong/game"
  ) {
    return;
  }
  const languageButtons = document.querySelectorAll(".btn-check");
  const isLogin = sessionStorage.getItem("login");
  languageButtons.forEach((button) => {
    if (button.id === lang) {
      button.checked = true;
    } else {
      button.checked = false;
    }
  });

  // header footer 언어 변경
  const headerTitle = document.querySelector("#main-title");
  headerTitle.textContent = MainTitleLanguageHtml[lang];

  const footerProfile = document.querySelector("#profile-btn");
  footerProfile.textContent = ProfileLanguageHtml[lang];

  document.querySelectorAll("label[data-lang]").forEach((label) => {
    const langKey = label.getAttribute("for");
    label.textContent = LanguageButtonHtml[lang][langKey];
  });

  const headerLogin = document.getElementById("login");
  if (isLogin) {
    headerLogin.textContent = "42 logout";
  }
  // TODO - 빨리 만들라 시키기
  // 로그인 전략이 없어서 못만듬/./
  // const login_button = document.getElementById("login_button");
  // login_button.textContent = "42 logout";
};
