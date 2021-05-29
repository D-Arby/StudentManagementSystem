#pragma once

#include <string>
#include <vector>
using namespace std;

class Course
{
private:
	string name;
	string code;
	int maxStudents;
	int hours;
	vector<Course> prerequired;

public:
	Course(string name, string code, int max, int hours);
	string get_name();
	string get_code();
	int get_max_students();
};

