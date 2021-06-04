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

void Student::set_password(string password)
{
	this->password = password;
}

void Student::set_year(int year)
{
	this->year = year;
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

void Student::view_course_details(vector<Course> courses)
{
	int flag = 0;
	string code;

	while (true)
	{
		cout << "Enter course code: ";
		cin >> code;

		for (Course course : courses)
		{
			if (course.get_code() == code)
			{
				flag = 1;
				cout << "Course name: " << course.get_name() << " (" << course.get_code() << ")" << endl;
				cout << "Max students: " << course.get_max_students() << endl;
				cout << "Hours: " << course.get_hours() << endl;
				cout << "Required courses: \n";
				for (Course req : course.get_required())
				{
					cout << "\tCourse name: " << req.get_name() << " (" << course.get_code() << ")" << endl;
				}
				break;
			}
		}

		if (!flag)
		{
			cout << "Course not found. Please enter a valid code.\n";
			continue;
		}

		break;
	}
}

void Student::view_available_courses(vector<Course>& courses)
{
	cout << "------ Available courses ------\n\n";

	for (Course course : courses)
	{
		cout << "Course Name: " << course.get_name() << " (" << course.get_code() << ")" << endl;

		for (Course Finished : finished)
		{
			if (course.get_code() == Finished.get_code())
			{
				cout << "You have finished this Course " << endl;
			}

			break;
		}

		for (Course InProgress : inProgress)
		{
			if (course.get_code() == InProgress.get_code())
			{
				cout << "This Course is in Progress " << endl;
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

void Student::edit_data(vector<Course> courses)
{
	int option;

	while (true)
	{
		system("CLS");
		cout << "1) Edit password\n2) Add finished course\n3) Edit academic year\n4) Exit\n\n>>> ";
		cin >> option;
		system("CLS");
		if (option == 1)
		{
			string new_password;
			cout << "Enter new password: ";
			cin >> new_password;
			this->set_password(new_password);
			continue;
		}

		else if (option == 2)
		{
			string code;
			int flag;
			while (true)
			{
				flag = 0;
				cout << "Enter finished course code: ";
				cin >> code;
				for (Course course : courses)
				{
					if (course.get_code() == code)
					{
						flag = 1;
						this->get_finished().push_back(course);
						for (Course required : course.get_required())
						{
							if (find(finished.begin(), finished.end(), required) != finished.end())
							{
								finished.push_back(required);
							}
						}
					}
				}

				if (!flag)
				{
					cout << "Course not found. Please add a valid code.\n";
					continue;
				}

				break;
			}

			continue;
		}

		else if (option == 3)
		{
			int new_year;
			
			while (true)
			{
				cout << "Enter new academic year: ";
				cin >> new_year;
				if (new_year < 1 || new_year > 4)
				{
					cout << "Invalid year. Please enter a value between 1 and 4.\n";
					continue;
				}

				break;
			}

			this->set_year(new_year);
		}

		else
		{
			break;
		}
	}
}