#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"college.h"
using std::string;
using std::vector;
using std::cout;
class major
{
private:
	//רҵ�����е�����Ϊ�����ƣ�������𣬼�飬�������ѧУ����ƽ��н��
	string name_;
	string introduction_;
	int category_;
	string industry_;
	string work_;
	string city_;
	int income_;
	vector<string> open_school_;
public:
	major() {}
	void set_message(string name, string introduction, int category
		, int income, string industry, string work, string city, vector<string>& open_school) {
		name_ = name;
		introduction_ = introduction;
		category_ = category;
		income_ = income;
		industry_ = industry;
		work_ = work;
		city_ = city;
		open_school_ = open_school;
	}
    string introduction()const { return introduction_; }
	int category()const { return category_; }
	string name()const { return name_; }
	int income()const { return income_; }
	void major_message()const;
};

