#pragma once

#include <string>
#include "Student.h"
using namespace std;

class Admin
{
private:
	string name;
	string password;

public:
	Admin(string name, string password);
	string get_name();
	string get_password();
	void add_student(vector<Student> &students);
	void add_course(vector<Course> &courses);
};