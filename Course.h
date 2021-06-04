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
	vector<Course> required;

public:
	Course(string name, string code, int max, int hours);
	bool operator == (Course const& obj);
	string get_name();
	string get_code();
	int get_max_students();
	int get_hours();
	void set_name(string name);
	void set_code(string code);
	void set_maxStudents(int max);
	void set_hours(int hours);
	vector<Course>& get_required();
};

