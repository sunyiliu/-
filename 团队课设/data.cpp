#include "data.h"
#include<fstream>
using std::ifstream;
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
int degree(string s1, string s2) {
	int d = 0;
	if (s1 == "p_A") d = 7;
	if (s1 == "A+") d = 6;
	if (s1 == "A") d = 5;
	if (s1 == "B+") d = 4;
	if (s1 == "B") d = 3;
	if (s1 == "C") d = 2;
	if (s1 == "D")d = 1;
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
	int major_code[150] = { 0 };
	double grade[3];
	double rank[3];
	int num = 0;
	string name, web, city, d1, d2;
	int plan_p, QS_rank;
	bool is_211, is_985, is_double;
	//添加学校，苦逼操作
	//名称，官网地址，所在城市，要求评级，计划人数，三年最低录取排名，所含专业，
	//三年最低最低分，学校QS排名，是不是211，是不是985，是不是双一流
	file >> num;
	college a;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 3; j++)
			file >> grade[j];
		for (int j = 0; j < 3; j++)
			file >> rank[j];
		file >> name >> web >> city >> d1 >> d2 >> plan_p >> QS_rank >> is_211 >> is_985 >> is_double;
		a.set_message(name, web, city, degree(d1, d2), plan_p, rank, major_code, grade, QS_rank
			, is_211, is_985, is_double);
		colleges_reference.insert(a);
	}
	/*
	grade[0] = 387; grade[1] = 378; grade[2] = 374;
	rank[0] = 7545; rank[1] = 6969; rank[2] = 6303;
	college a("南京理工大学", "http://www.njust.edu.cn/", "南京"
		, degree("p_A", "B"), 480, rank, major_code, grade, 40, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 399; grade[1] = 391; grade[2] = 387;
	rank[0] = 2275; rank[1] = 1905; rank[2] = 2054;
	a.set_message("南京大学", "https://www.nju.edu.cn/", "南京"
		, degree("A", "A"), 617, rank, major_code, grade, 7, true, true, true);
	colleges_reference.insert(a);
	grade[0] = 398; grade[1] = 388; grade[2] = 384;
	rank[0] = 2535; rank[1] = 2673; rank[2] = 2716;
	a.set_message("东南大学", "https://www.seu.edu.cn/", "南京"
		, degree("p_A", "B"), 452, rank, major_code, grade, 26, true, true, true);
	colleges_reference.insert(a);
	grade[0] = 383; grade[1] = 359; grade[2] = 368;
	rank[0] = 10428; rank[1] = 25683; rank[2] = 9700;
	a.set_message("河海大学", "http://www.hhu.edu.cn/", "南京"
		, degree("A", "B"), 906, rank, major_code, grade, 93, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 371; grade[1] = 361; grade[2] = 354;
	rank[0] = 23755; rank[1] = 22956; rank[2] = 22815;
	a.set_message("南京农业大学", "http://www.njau.edu.cn/", "南京"
		, degree("A", "B"), 582, rank, major_code, grade, 71, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 376; grade[1] = 367; grade[2] = 360;
	rank[0] = 17387; rank[1] = 15908; rank[2] = 16287;
	a.set_message("南京师范大学", "http://www.njnu.edu.cn/", "南京"
		, degree("A", "B"), 1396, rank, major_code, grade, 66, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 368; grade[1] = 356; grade[2] = 354;
	rank[0] = 28148; rank[1] = 30126; rank[2] = 22815;
	a.set_message("中国药科大学", "http://www.cpu.edu.cn/", "南京"
		, degree("A", "B"), 550, rank, major_code, grade, 86, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 388; grade[1] = 379; grade[2] = 375;
	rank[0] = 6927; rank[1] = 6385; rank[2] = 5830;
	a.set_message("南京航空航天大学", "http://www.nuaa.edu.cn/", "南京"
		, degree("p_A", "B"), 600, rank, major_code, grade, 42, true, false, true);
	colleges_reference.insert(a);
	grade[0] = 359; grade[1] = 340; grade[2] = 345;
	rank[0] = 44011; rank[1] = 58853; rank[2] = 35017;
	a.set_message("南京工业大学", "http://www.njtech.edu.cn/", "南京"
		, degree("B", "B"), 2482, rank, major_code, grade, 94, false, false, false);
	colleges_reference.insert(a);
	grade[0] = 358; grade[1] = 348; grade[2] = 338;
	rank[0] = 46035; rank[1] = 43537; rank[2] = 46350;
	a.set_message("南京林业大学", "https://www.njfu.edu.cn/", "南京"
		, degree("B", "B"), 897, rank, major_code, grade, 125, false, false, true);
	colleges_reference.insert(a);
	grade[0] = 369; grade[1] = 359; grade[2] = 353;
	rank[0] = 26626; rank[1] = 25683; rank[2] = 24009;
	a.set_message("南京邮电大学", "http://www.njupt.edu.cn/", "南京"
		, degree("B", "B"), 1898, rank, major_code, grade, 132, false, false, true);
	colleges_reference.insert(a);
	grade[0] = 359; grade[1] = 350; grade[2] = 342;
	rank[0] = 44011; rank[1] = 39968; rank[2] = 39641;
	a.set_message("南京信息工程大学", "https://www.nuist.edu.cn/", "南京"
		, degree("B", "B"), 2568, rank, major_code, grade, 165, false, false, true);
	colleges_reference.insert(a);
	file.close();
	*/
};
void data_base::read_major() {};