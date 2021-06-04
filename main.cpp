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

	Student student1("Abdelrahman", "20191700343", "567308246", 2);
	Student student2("Seif", "20191700310", "1597532846", 2);
	Student student3("Shehab", "20191700350", "147852369", 2);

	Course course1("OOP", "CS150", 50, 3);
	Course course2("SP", "CS170", 100, 3);
	Course course3("Introduction to CS", "CS101", 200, 2);
	Course course4("Calculus", "BSC99", 120, 3);
	Course course5("Physics", "BSC210", 150, 3);

	course1.get_required().push_back(course2);
	course2.get_required().push_back(course3);
	course5.get_required().push_back(course4);

	student1.get_finished().push_back(course3);
	student1.get_inProgress().push_back(course4);

	vector<Course> courses;
	vector<Student> students;

	courses.push_back(course1);
	courses.push_back(course2);
	courses.push_back(course3);
	courses.push_back(course4);
	courses.push_back(course5);

	students.push_back(student1);
	students.push_back(student2);
	students.push_back(student3);

	int user;

	while (true)
	{
		cout << "1) Admin\n2) Student\n3) Exit\n\n>>> ";
		cin >> user;

		if (user == 1)
		{
			//admin control code
			string admin_name, admin_password;
			system("CLS");

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
				system("CLS");
				cout << "1) Add new student\n2) Add new course\n3) Enter course prerequisite\n4) View list of all students in a specific course\n";
				cout << "5) View list of all courses of a specific student\n6) Edit course data\n7) Go back\n\n>>> ";
				cin >> admin_option;
				system("CLS");
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
					admin.add_prerequisite(courses);
					continue;
				}

				else if (admin_option == 4)
				{
					admin.view_students(students, courses);
					system("pause");
					continue;
				}

				else if (admin_option == 5)
				{
					admin.view_courses(students);
					system("pause");
					continue;
				}

				else if (admin_option == 6)
				{
					admin.edit_course(courses);
					continue;
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
			string id, password;
			int index;
			int flag = 0;
			system("CLS");

			while (true)
			{
				cout << "ID: ";
				cin >> id;
				cout << "Password: ";
				cin >> password;

				for (Student student : students)
				{
					if (student.get_id() == id && student.get_password() == password)
					{
						auto it = find(students.begin(), students.end(), student);
						index = it - students.begin();
						flag = 1;
						break;
					}
				}

				if (!flag)
				{
					cout << "Invalid ID or password. Please try again.\n";
					continue;
				}

				break;
			}

			int student_option;

			while (true)
			{
				system("CLS");
				cout << "1) View available courses\n2) View a specific course\n3) Register for a course\n4) View your courses\n";
				cout << "5) Edit your data\n6) Go back\n\n>>> ";
				cin >> student_option;
				system("CLS");

				if (student_option == 1)
				{
					students[index].view_available_courses(courses);
				}

				else if (student_option == 2)
				{
					students[index].view_course_details(courses);
				}

				else if (student_option == 3)
				{
					students[index].register_course(courses);
				}

				else if (student_option == 4)
				{
					students[index].view_courses();
				}

				else if (student_option == 5)
				{
					students[index].edit_data(courses);
				}

				else
				{
					break;
				}

				system("pause");
			}

			continue;
		}

		else
		{
			return 0;
		}
	}
}