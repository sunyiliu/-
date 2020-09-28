#pragma once
#include<set>
#include<vector>
#include<map>
#include<iostream>
#include"college.h"
#include"major.h"
using std::multiset;
using std::map;
struct rule1 {
	bool operator() (const college& a, const college& b) const {
		if (a.degree() != b.degree())return a.degree() > b.degree();
		else return a.ave_rank() < b.ave_rank();
	}
};
class data_base
{
public:
	multiset<college, rule1> colleges_reference;
	map<int, major> majors_reference;
	double grade_rank_reference[2][461];
	void read_major();
	void grade_rank();
	void read_college();
	data_base() {
		read_major();
		grade_rank();
		read_college();
	}
};

