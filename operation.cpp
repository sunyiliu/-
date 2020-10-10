#include "operation.h"
extern string category_reference[11];
struct rule2 {
	bool operator()(const college& a, const college& b) const {
		return a.ave_rank() < b.ave_rank();
	}
};
struct rule3 {
	bool operator()(const college& a, const college& b) const {
		return a.college_rank() < b.college_rank();
	}
};
void operation::recommend(int& degree, int& grade) {
	multiset<college>::iterator p;
	int r = 0;
	if (degree < 23)r = 1;
	int s = data_.grade_rank_reference[r][grade];
	//���������������ѧУ
	for (p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		if (p->degree() <= degree)break;
	}
	//���������������ѧУ
	//���
	cout << "���Գ��ѧУ��\n";
	for (; p != data_.colleges_reference.end(); p++) {
		if (p->ave_rank() >= data_.grade_rank_reference[r][grade + 2] && p->ave_rank() <= data_.grade_rank_reference[r][grade]) {
			p->college_basic();
		}
		else if (p->ave_rank() > data_.grade_rank_reference[r][grade])break;
	}
	//�ȵ�
	cout << "�����ȵ�ѧУ��\n";
	for (; p != data_.colleges_reference.end(); p++) {
		if (p->ave_rank() >= data_.grade_rank_reference[r][grade - 1] && p->ave_rank() <= data_.grade_rank_reference[r][grade - 4]) {
			p->college_basic();
		}
		else if (p->ave_rank() > data_.grade_rank_reference[r][grade - 4])break;
	}
	//����
	cout << "���Ա���ѧУ��\n";
	for (; p != data_.colleges_reference.end(); p++) {
		if (p->ave_rank() >= data_.grade_rank_reference[r][grade - 5] && p->ave_rank() <= data_.grade_rank_reference[r][grade - 7]) {
			p->college_basic();
		}
		else if (p->ave_rank() > data_.grade_rank_reference[r][grade - 7])break;
	}
};
void operation::search_major(string&name) {
	for (multimap<int, major>::iterator p = data_.majors_reference.begin(); p != data_.majors_reference.end(); p++) {
		if ((p->second).name() == name) {
			(p->second).major_message();
			break;
		}
	}
}
void operation::search_college(string&name) {
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++)
		if (p->name()== name) {
			p->college_message();
			break;
		}
}
void operation::totall_colleges() {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		p->college_basic();
	}
}
void operation::appoint_province_colleges(int province) {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		if (p->province() == province)p->college_basic();
	}
}
void operation::appoint_city_colleges(string city) {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		if (p->city() == city)p->college_basic();
	}
}
void operation::totall_211_colleges() {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		if (p->is_211())p->college_basic();
	}
}
void operation::totall_985_colleges() {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		if (p->is_985())p->college_basic();
	}
}
void operation::totall_double_first_class_colleges() {
	multiset<college, rule3>t_college;
	for (multiset<college>::iterator p = data_.colleges_reference.begin(); p != data_.colleges_reference.end(); p++) {
		t_college.insert(*p);
	}
	for (multiset<college>::iterator p = t_college.begin(); p != t_college.end(); p++) {
		if (p->is_double_first_class())p->college_basic();
	}
}
void operation::totall_majors() {
	//��ӡ����רҵ
	multimap<int, major>::iterator p = data_.majors_reference.begin();
	for (int i = 0; i < 11; i++)
	{
		cout << category_reference[i] << "��\n";
		print_appoint_majors(p, i);
	}
}
void operation::print_appoint_majors(multimap<int, major>::iterator p ,int category) {
	for (; p != data_.majors_reference.end(); p++)
	{
		if ((p->second).category() == category)
			cout << (p->second).name() << '\n';
		else break;
	}
}