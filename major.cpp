#include "major.h"
string category_reference[11] = { "��ѧ","����ѧ","��ʷѧ","����ѧ","��ѧ"
,"��ѧ","��ѧ","��ѧ","ҽѧ","����ѧ","ũѧ" };
void major::major_message()const {
    cout << "����" <<name_<< " ����ѧ�ƣ�" << category_reference[category_]<<'\n';
    cout << "    ";
    for (int i = 4; i < introduction_.size()+4; i++) {
        if (i % 80 == 0)cout << '\n';
        cout << introduction_[i-4];
    }
    cout << "��ƽ��н�ʣ�" << income_<<" ����ҵ��ҵ��"<<industry_<<'\n';
    cout << "����ҵ��λ��" << work_ << " ����ҵ������" << city_ << '\n';
    cout << "����ԺУ��\n";
    for (int i = 0; i < open_school_.size(); i++)
        cout << open_school_[i] << '\n';
};