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
	int flag;
	cout << "------ Adding new student ------\n";
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	
	while (true)
	{
		flag = 1;
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
	int flag;

	cout << "------ Adding new course ------\n";

	while (true)
	{
		flag = 1;
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

	while (true)
	{
		flag = 1;
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

void Admin::view_students(vector<Student> students, vector<Course> courses)
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

	for (Student student : students)
	{
		for (Course course : student.get_finished())
		{
			if (course.get_code() == code)
			{
				cout << "Student Name:" << student.get_name() << endl;
				cout << "Student ID:" << student.get_id() << endl;
				break;
			}
		}

		for (Course course : student.get_inProgress())
		{
			if (course.get_code() == code)
			{
				cout << "Student Name:" << student.get_name() << endl;
				cout << "Student ID:" << student.get_id() << endl;
				break;
			}
		}
	}
}

void Admin::view_courses(vector<Student> students)
{
	int flag = 0;
	string id;

	while (true)
	{
		cout << "Enter student ID: ";
		cin >> id;

		for (Student student : students)
		{
			if (student.get_id() == id)
			{
				flag = 1;
				break;
			}
		}

		if (!flag)
		{
			cout << "ID not found. Please enter a valid ID.\n";
			continue;
		}

		break;
	}

	for (Student student : students)
	{
		for (Course course : student.get_finished())
		{
			if (student.get_id() == id)
			{
				cout << "Course Name:" << course.get_name() << endl;
				cout << "Course COde:" << course.get_code() << endl;
				break;
			}
		}
		for (Course course : student.get_inProgress())
		{
			if (student.get_id() == id)
			{
				cout << "Course Name:" << course.get_name() << endl;
				cout << "Course COde:" << course.get_code() << endl;
				break;
			}
		}
	}
}

void Admin::edit_course(vector<Course>& courses)
{
	string code;
	int flag = 0;
	int index = 0;

	while (true)
	{
		cout << "Enter course code: ";
		cin >> code;
		for (Course course : courses)
		{
			if (course.get_code() == code)
			{
				auto it = find(courses.begin(), courses.end(), course);
				index = it - courses.begin();
				flag = 1;
			}
		}

		if (!flag)
		{
			cout << "Course not found. Please enter a valid code.\n";
			continue;
		}

		break;
	}

	string new_name, new_code;
	int new_max, new_hours;
	int size = courses.size();

	while (true)
	{
		flag = 1;
		cout << "Enter new course name: ";
		cin.ignore();
		getline(cin, new_name);

		for (int i = 0; i < size; i++)
		{
			if (i != index && courses[i].get_name() == new_name)
			{
				flag = 0;
				break;
			}
		}

		if (!flag)
		{
			cout << "Course name already exists. Please enter a unique name.\n";
			continue;
		}

		break;
	}

	flag = 1;

	while (true)
	{
		flag = 1;
		cout << "Enter new course code: ";
		cin >> new_code;

		for (int i = 0; i < size; i++)
		{
			if (i != index && courses[i].get_code() == new_code)
			{
				flag = 0;
				break;
			}
		}

		if (!flag)
		{
			cout << "Course code already exists. Please enter a unique code.\n";
			continue;
		}

		break;
	}

	while (true)
	{
		cout << "Enter new max students: ";
		cin >> new_max;
		if (new_max < 1 || new_max > 500)
		{
			cout << "Invalid number. please enter a number between 1 and 500.\n";
			continue;
		}

		break;
	}

	while (true)
	{
		cout << "Enter new course hours: ";
		cin >> new_hours;
		if (new_hours < 1 || new_hours > 4)
		{
			cout << "Invalid number. please enter a number between 1 and 4.\n";
			continue;
		}

		break;
	}

	courses[index].set_name(new_name);
	courses[index].set_code(new_code);
	courses[index].set_maxStudents(new_max);
	courses[index].set_hours(new_hours);
	
	courses[index].get_required().clear();
}