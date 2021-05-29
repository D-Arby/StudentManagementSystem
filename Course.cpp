#include "Course.h"

Course::Course(string name, string code, int max, int hours)
{
	this->name = name;
	this->code = code;
	this->maxStudents = max;
	this->hours = hours;
}

string Course::get_name()
{
	return name;
}

string Course::get_code()
{
	return code;
}

int Course::get_max_students()
{
	return maxStudents;
}
