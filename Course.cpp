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

void Course::set_name(string name)
{
	this->name = name;
}

void Course::set_code(string code)
{
	this->code = code;
}

void Course::set_maxStudents(int max)
{
	this->maxStudents = max;
}

void Course::set_hours(int hours)
{
	this->hours = hours;
}

vector<Course>& Course::get_required()
{
	return required;
}
