#include "Student.h"

Student::Student(string name, string id, string password, int year)
{
	this->name = name;
	this->id = id;
	this->password = password;
	this->year = year;
}

string Student::get_name()
{
	return name;
}

string Student::get_id()
{
	return id;
}

string Student::get_password()
{
	return password;
}

string Student::get_year()
{
	return to_string(year);
}

vector<Course> Student::get_finished()
{
	return finished;
}

vector<Course> Student::get_inProgress()
{
	return inProgress;
}