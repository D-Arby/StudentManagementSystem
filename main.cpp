#include <iostream>
#include <string>
#include <vector>
#include "Admin.h"
#include "Course.h"
#include "Student.h"
using namespace std;

int main()
{
	Admin admin("admin", "123456789");
	vector<Course> courses;
	vector<Student> students;

	int user;

	while (true)
	{
		cout << "1) Admin\n2) Student\n3) Exit\n\n>>> ";
		cin >> user;

		if (user == 1)
		{
			//admin control code
			string admin_name, admin_password;

			while (true)
			{
				cout << "Name: ";
				cin >> admin_name;
				cout << "Password: ";
				cin >> admin_password;

				if (admin_name != admin.get_name() || admin_password != admin.get_password())
				{
					cout << "Invalid name or password. Please try again.\n\n";
					continue;
				}

				break;
			}

			int admin_option;

			while (true)
			{
				cout << "1) Add new student\n2) Add new course\n3) Enter course prerequisite\n4) View list of all students in a specific course\n";
				cout << "5) View list of all courses of a specific student\n6) Edit course data\n7) Go back\n\n>>> ";
				cin >> admin_option;

				if (admin_option == 1)
				{
					admin.add_student(students);
					continue;
				}

				else if (admin_option == 2)
				{
					admin.add_course(courses);
					continue;
				}

				else if (admin_option == 3)
				{
					//course prerequisite code
				}

				else if (admin_option == 4)
				{
					//students viewing code
					//function should iterate over the students vector and check for the specific course
					//and then prints the student's details if it matches the course code entered
				}

				else if (admin_option == 5)
				{
					//function should print all courses of a student
				}

				else if (admin_option == 6)
				{
					//function should take a code as input and allows the admin to enter new data for the course
				}

				else
				{
					break;
				}
			}

			continue;
		}

		else if (user == 2)
		{
			//student control code
		}

		else
		{
			return 0;
		}
	}
}