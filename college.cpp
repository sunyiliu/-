#include "college.h"
extern string province_reference[34];
void college::set_message(string name, string official_web, string location, int degree, int plan_people
	, double* enroll_lowest_rank, vector<string>& open_major, double* score, int rank, bool is_211
	, bool is_985, bool is_double_first_class,int province) {
	name_ = name;
	official_web_ = official_web;
	location_ = location;
	for (int i = 0; i < 3; i++)
		score_[i] = score[i];
	degree_ = degree;
	plan_people_ = plan_people;
	for (int i = 0; i < 3; i++)
		enroll_lowest_rank_[i] = enroll_lowest_rank[i];
	open_major_ = open_major;
	is_211_ = is_211;
	is_985_ = is_985;
	is_double_first_class_ = is_double_first_class;
	rank_ = rank;
	province_ = province;
}
void college::college_message()const {
	//���ѧУȫ����Ϣ
	cout << name_<<" QS������"<<rank_<< (is_double_first_class_ ? " ˫һ��" : "       ");
	cout <<(is_985_ ? " 985" : "    ");
	cout <<(is_211_ ? " 211" : "    ");
	cout << " ѧУ���ڵأ�" << province_reference[province_] << ' ' << location_;
	cout << " ������¼ȡ��ͷ�����" << score_[0] << ' ' << score_[1] << ' ' << score_[2] << '\n';
	cout << "������¼ȡ���������" << enroll_lowest_rank_[0] << ' ' << enroll_lowest_rank_[1] << ' ' << enroll_lowest_rank_[2] << '\n';
	cout << "����ƻ�����������" << plan_people_ << '\n';
	cout << "ѧУ�Ĺ�����ַ��" << official_web_ << '\n';
	cout << "����רҵ��\n";
	open_major();
}
void college::college_basic()const {
	 //ֻ���ѧУ������������
	cout << "QS������" << rank_ << ' ' << name_;
	cout << (is_double_first_class_ ? " ˫һ��" : "       ");
	cout << (is_985_ ? " 985" : "    ");
	cout << (is_211_ ? " 211" : "    ")<< '\n';
}