import { language } from "../components/language";
import {
  DiceRoomPageLanguage,
  PongRoomPageLanguage,
} from "../components/languageHtml";
import PageView from "./Pageview";

class DiceRoom extends PageView {
  constructor(params) {
    super();
    // console.log("asdfad", params);
    this.id = params.id;
  }

  async getHtml() {
    const html = DiceRoomPageLanguage(this.id)[language];
    return html;
    // return `<h1>Game ${this.id}</h1>`;
  }
}
export default DiceRoom;
