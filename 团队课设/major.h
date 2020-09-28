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
	string name_;
	string introduction_;
	string category_;
	string open_school_web_;
public:
	major() {}
	void set_message(string name, string introduction, string category, string& open_school_web) {
		name_ = name;
		introduction_ = introduction;
		category_ = category;
		open_school_web_ = open_school_web;
	}
	string introduction() { return introduction_; }
	string category() { return category_; }
	string name() { return name_; }
};

