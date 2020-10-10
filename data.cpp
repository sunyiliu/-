#include "data.h"
#include<fstream>
#include<algorithm>
using std::ifstream;
using std::pair;
string province_reference[34] = { "����","�Ϻ�","�㽭","����" };
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
//���ò�ͬ�ȼ���Ӧ�ķ���
int degree(string s1, string s2) {
	int d = 0;
	if (s1 == "A+")d = 6;
	if (s1 == "A") d = 5;
	if (s1 == "B+")d = 4;
	if (s1 == "B") d = 3;
	if (s1 == "C") d = 2;
	if (s1 == "D") d = 1;
	if (s2 == "A+") d = d * 10 + 6;
	if (s2 == "A") d = d * 10 + 5;
	if (s2 == "B+") d = d * 10 + 4;
	if (s2 == "B") d = d * 10 + 3;
	if (s2 == "C") d = d * 10 + 2;
	if (s2 == "D")d = d * 10 + 1;
	return d;
}
void data_base::grade_rank() {
	ifstream file("score_rank.txt");
	for (int i = 1; i >= 0; i--) {
		for (int j = 426; j >= 347; j--)
			file >> grade_rank_reference[i][j];
	}
	file.close();
}
void data_base::read_college() {
	ifstream file("college_message.txt");
	double grade[3];
	double rank[3];
	int num = 0;
	string name, web, city, d1, d2;
	int plan_p, QS_rank,province,major_num;
	bool is_211, is_985, is_double;
	//���ѧУ����Ʋ���
	//���ƣ�������ַ�����ڳ��У�Ҫ���������ƻ��������������¼ȡ����������רҵ��
	//���������ͷ֣�ѧУQS�������ǲ���211���ǲ���985���ǲ���˫һ��������ʡ��
	file >> num;
	college a;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++)
			file >> grade[j];
		for (int j = 0; j < 3; j++)
			file >> rank[j];
		file >> name >> web >> city >> d1 >> d2 >> plan_p >> QS_rank >> is_211 >> is_985 >> is_double>> province>>major_num;
		vector<string> open_major(major_num);
		for (int j = 0; j < major_num; j++)
			file >> open_major[j];
		a.set_message(name, web, city, degree(d1, d2), plan_p, rank,open_major, grade, QS_rank
			, is_211, is_985, is_double, province);
		colleges_reference.insert(a);
	}
	file.close();
}
void data_base::read_major() {
	//���רҵ����Ʋ���
	//���ƣ�רҵ��飬����ѧ�ƣ���ƽ��н�ʣ�����ҵ��ҵ������ҵ��λ
	//����ҵ����������ԺУ
	ifstream file("major_message.txt");
	int num,category, income,open_num;
	string name, introduction,city,industry, work;
	major a;
	file >> num;
	for (int i = 0; i < num;i++) {
			file >> name >> introduction >> city >> industry >> work >> category >> income;
			file >> open_num;
			vector<string> open_school(open_num); 
			for (int k = 0; k < open_num; k++)
				file >> open_school[k];
			a.set_message(name, introduction, category
				, income, industry, work, city,open_school);
			pair<int, major> p(category,a);
			majors_reference.insert(p);
	}
}