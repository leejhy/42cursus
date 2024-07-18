import { navigateTo, router } from "./components/router";
import { resetPlayers } from "./components/state";

document.addEventListener("DOMContentLoaded", () => {
  document.body.addEventListener("click", (e) => {
    // data-link가 있는 속성 (이동 가능하게 만듬)
    // url이 바뀌면서 새로운 데이터들을 불러올때 실행
    if (e.target.matches("[data-link]")) {
      // console.log("click data-link");
      e.preventDefault();
      // navigateTo(e.target.href);
    }
  });
  // 라우팅 (view불러오기)
  // console.log("DOMContentLoaded router");
  // 클릭한다고 이 페이지로 가는 것은 아님 -> 정보가 바뀔때 해당 url로 라우팅
  // router();
  // console.log(window.location.pathname);
  // router();

	const path = window.location.pathname;

// if (path === "/main") router();
// else navigateTo(); 

  if (path === "/dice" 
    || path === "/pong" 
    || path === "/profile"
    || path === "/statistics"
    || path === "/pong/room/2"
    || path === "/pong/room/4") {
      navigateTo();
    } else {
    router();
    }
});

window.addEventListener("popstate", () => {
  console.log("popstate");
  resetPlayers();
  router();
});
 
