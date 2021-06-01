#include "Course.h"

Course::Course(string name, string code, int max, int hours)
{
	this->name = name;
	this->code = code;
	this->maxStudents = max;
	this->hours = hours;
}

bool Course::operator==(Course const& obj)
{
	return this->code == obj.code;
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

int Course::get_hours()
{
	return hours;
}

vector<Course>& Course:: get_required()
{
	return required;
}
