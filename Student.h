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
	bool operator == (Student const& obj);
	string get_name();
	string get_id();
	string get_password();
	string get_year();
	vector<Course>& get_finished();
	vector<Course>& get_inProgress();
	void view_courses();
	void view_available_courses(vector<Course>& courses);
	void register_course(vector<Course>& courses);
};