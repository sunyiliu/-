#include "major.h"
string category_reference[11] = { "哲学","经济学","历史学","教育学","文学"
,"法学","理学","工学","医学","管理学","农学" };
void major::major_message()const {
    cout << "名称" <<name_<< " 所属学科：" << category_reference[category_]<<'\n';
    cout << "    ";
    for (int i = 4; i < introduction_.size()+4; i++) {
        if (i % 80 == 0)cout << '\n';
        cout << introduction_[i-4];
    }
    cout << "月平均薪资：" << income_<<" 最多就业行业："<<industry_<<'\n';
    cout << "最多就业岗位：" << work_ << " 最多就业地区：" << city_ << '\n';
    cout << "开设院校：\n";
    for (int i = 0; i < open_school_.size(); i++)
        cout << open_school_[i] << '\n';
};