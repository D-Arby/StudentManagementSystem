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

void Admin::add_student(vector<Student>& students)
{
	string name, id, password;
	int year;
	int flag = 1;
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
				flag = 0;
				break;
			}
		}

		if (!flag)
		{
			continue;
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
	int flag = 1;

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
				flag = 0;
				break;
			}
		}

		if (!flag)
		{
			continue;
		}

		break;
	}

	flag = 1;

	while (true)
	{
		cout << "Code: ";
		cin >> code;

		for (Course course : courses)
		{
			if (course.get_code() == code)
			{
				cout << "Course already exists. Please choose another code.\n";
				flag = 0;
				break;
			}
		}

		if (!flag)
		{
			continue;
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

void Admin::add_prerequisite(vector<Course>& courses)
{
	string course_code;
	int flag = 0;
	int course_index;

	while (true)
	{
		cout << "Enter course code: ";
		cin >> course_code;

		for (Course course : courses)
		{
			if (course.get_code() == course_code)
			{
				flag = 1;

				auto it = find(courses.begin(), courses.end(), course);
				course_index = it - courses.begin();

				break;
			}
		}

		if (!flag)
		{
			cout << "Course doesn't exist. Please enter a valid code.\n";
			continue;
		}

		break;
	}

	flag = 0;

	cout << "Is the prerequisite course\n1) An existing course\n2) A new course\n>>> ";

	int pre_type;
	cin >> pre_type;

	if (pre_type == 1)
	{
		string required_course_code;
		int required_course_index;

		while (true)
		{
			//Loop to check for the existence of the code
			while (true)
			{
				cout << "Enter required course code: ";
				cin >> required_course_code;

				for (Course course : courses)
				{
					if (course.get_code() == required_course_code)
					{
						flag = 1;

						auto it = find(courses.begin(), courses.end(), course);
						required_course_index = it - courses.begin();

						break;
					}
				}

				if (!flag)
				{
					cout << "Course doesn't exist. Please enter a valid code.\n";
					continue;
				}

				break;
			}

			flag = 1;

			for (Course course : courses[required_course_index].get_required())
			{
				if (course.get_code() == course_code)
				{
					flag = 0;
					break;
				}
			}

			if (!flag)
			{
				cout << "Course mismatch. Please enter a valid course.\n";
				continue;
			}
			
			else
			{
				break;
			}
		}

		courses[course_index].get_required().push_back(courses[required_course_index]);
	}

	else
	{
		//Add course and then add it to the vector
		add_course(courses);
		courses[course_index].get_required().push_back(courses[courses.size() - 1]);
	}
}