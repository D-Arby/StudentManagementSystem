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
	void add_student(vector<Student>& students);
	void add_course(vector<Course>& courses);
	void add_prerequisite(vector<Course>& courses);
	void view_students(vector<Student> students, vector<Course> courses);
	void view_courses(vector<Student> students);
	void edit_course(vector<Course>& courses);
};