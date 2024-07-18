import { ProfileGetData } from "../components/fetch";
import { language } from "../components/language";
import { ProfilePageLanguage } from "../components/languageHtml";
import PageView from "./Pageview";

class Profile extends PageView {
  constructor() {
    super();
  }

  async getHtml() {
    // const html = setSelectHtml();
    let data = await ProfileGetData();
    console.log("data", data);
    const html = ProfilePageLanguage(data)[language];
    return html;
  }
}
export default Profile;
