#include "Student.h"
#include <iostream>

Student::Student(string name, string id, string password, int year)
{
	this->name = name;
	this->id = id;
	this->password = password;
	this->year = year;
}

bool Student::operator==(Student const& obj)
{
	return this->id == obj.id;
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

vector<Course>& Student::get_finished()
{
	return finished;
}

vector<Course>& Student::get_inProgress()
{
	return inProgress;
}

void Student::view_courses()
{
	cout << "------ Your courses ------\n";
	cout << "1) Finished: \n";

	for (Course course : finished)
	{
		cout << "Course Name : " << course.get_name() << " (" << course.get_code() << ")" << endl;
	}

	cout << "\n2) In progress: \n";

	for (Course course : inProgress)
	{
		cout << "Course Name : " << course.get_name() << " (" << course.get_code() << ")" << endl;
	}

	cout << "\n\n";
}

void Student::view_available_courses(vector<Course>& courses)
{
	cout << "------ Available courses ------\n\n";

	for (Course course : courses)
	{
		cout << "Course Name: " << course.get_name() << endl;
		cout << "Course Code: " << course.get_code() << endl;
		cout << "Course Hours: " << course.get_hours() << endl;

		for (Course Finished : finished)
		{
			if (course.get_code() == Finished.get_code())
			{
				cout << " You have finished this Course " << endl;
			}

			break;
		}

		for (Course InProgress : inProgress)
		{
			if (course.get_code() == InProgress.get_code())
			{
				cout << " This Course is in Progress " << endl;
			}

			break;
		}

		cout << endl;
	}

	cout << "\n";
}

void Student::register_course(vector<Course>& courses)
{
	string code;
	int flag = 0;
	int index;

	while (true)
	{
		cout << "Enter the code for the course: ";
		cin >> code;
		for (Course course : courses)
		{
			if (course.get_code() == code)
			{
				auto it = find(courses.begin(), courses.end(), course);
				index = it - courses.begin();
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			cout << "Course not found. Please try again.\n";
			continue;
		}
		break;
	}

	flag = 1;

	for (Course course : finished)
	{
		if (courses[index].get_code() == course.get_code())
		{
			cout << "You have already finished this course.\n";
			flag = 0;
			break;
		}
	}

	if (flag)
	{
		for (Course InProgress : inProgress)
		{
			if (courses[index].get_code() == InProgress.get_code())
			{
				cout << "You have registered for this course before.\n";
				flag = 0;
				break;
			}
		}
	}

	if (flag)
	{
		int size = courses[index].get_required().size();
		int counter = 0;

		for (Course Req : courses[index].get_required())
		{
			for (Course Finished : finished)
			{
				if (Req.get_code() == Finished.get_code())
				{
					counter++;
				}
			}
		}

		if (size == counter)
		{
			cout << "You have registered for this Course Successfully.\n" << endl;
			inProgress.push_back(courses[index]);
		}
		else
		{
			cout << "You haven't finished all the prerequired courses for this course.\n" << endl;
		}
	}
}