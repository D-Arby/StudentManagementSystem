#pragma once

#include <string>
#include <vector>
#include "Course.h"
using namespace std;

class Student
{
private:
	string name;
	string id;
	string password;
	vector<Course> finished;
	vector<Course> inProgress;
	int year;

public:
	Student(string name, string id, string password, int year);
	string get_name();
	string get_id();
	string get_password();
	string get_year();
};

