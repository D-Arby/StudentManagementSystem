#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string name, string password)
{
	this->name = name;
	this->password = password;
}

string Admin::get_name()
{
	return name;
}

string Admin::get_password()
{
	return password;
}

void Admin::add_student(vector<Student> &students)
{
	string name, id, password;
	int year;
	cout << "------ Adding new student ------\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	
	while (true)
	{
		cout << "ID: ";
		cin >> id;

		for (Student student : students)
		{
			if (id == student.get_id())
			{
				cout << "ID already exists. Please choose a suitable ID.\n";
				continue;
			}
		}

		break;
	}

	cout << "Password: ";
	cin >> password;
	
	while (true)
	{
		cout << "Academic year: ";
		cin >> year;

		if (year < 1 || year > 4)
		{
			cout << "Invalid year. Please enter a year between 1 and 4.\n";
			continue;
		}

		break;
	}

	Student new_student(name, id, password, year);
	students.push_back(new_student);

	cout << "------ Student added successfully ------\n\n";
}

void Admin::add_course(vector<Course>& courses)
{
	string name, code;
	int max, hours;

	cout << "------ Adding new course ------\n";

	while (true)
	{
		cout << "Name: ";
		cin.ignore();
		getline(cin, name);

		for (Course course : courses)
		{
			if (course.get_name() == name)
			{
				cout << "Course already exists. Please choose another name.\n";
				continue;
			}
		}

		break;
	}

	while (true)
	{
		cout << "Code: ";
		cin >> code;

		for (Course course : courses)
		{
			if (course.get_code() == code)
			{
				cout << "Course already exists. Please choose another code.\n";
				continue;
			}
		}

		break;
	}

	while (true)
	{
		cout << "Max students: ";
		cin >> max;

		if (max < 1 || max > 500)
		{
			cout << "Invalid number. Please enter a number between 1 and 500.\n";
			continue;
		}

		break;
	}

	while (true)
	{
		cout << "Hours: ";
		cin >> hours;

		if (hours < 1 || hours > 4)
		{
			cout << "Invalid number. Please enter a number between 1 and 4.\n";
			continue;
		}

		break;
	}

	Course new_course(name, code, max, hours);
	courses.push_back(new_course);

	cout << "------ Course added successfully ------\n\n";
}