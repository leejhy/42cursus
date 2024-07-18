import { DiceStat } from "../components/fetch";
import { language } from "../components/language";
import { StatisticsPageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Statistics extends PageView {
  async getHtml() {
    // 지금까지 통계 정보 요청하기
    const data = await DiceStat();
    const html = StatisticsPageLanguage(data)[language];
    return html;
    // return `<h1>Game ${this.id}</h1>`;
  }
}
export default Statistics;
