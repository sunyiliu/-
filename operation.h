#pragma once
#include<fstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include"data.h"
using std::map;
using std::cout;
using std::vector;
using std::string;
using std::multiset;
class operation
{
private:
	data_base data_;
	void print_appoint_majors(map<int, major>::iterator p ,int category);
public:
	operation() {}
	void recommend(int& degree, int& grade);
	void transform_pushButton() {}
	void search_college(string&name);
	void search_major(string&name);
	void totall_colleges();
	void totall_majors();
	void appoint_province_colleges(int province);
	void appoint_city_colleges(string city);
	void totall_211_colleges();
	void totall_985_colleges();
	void totall_double_first_class_colleges();
	void open_IM();
};

