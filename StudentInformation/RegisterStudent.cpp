#include "Methods.h"
#include <iomanip>

void RegisterStudent()
{
	Student student;

	cout << "Name: ";
	cin >> student.name;

	cout << "Faculty number: ";
	cin >> student.fn;

	cout << "Group number: ";
	cin >> student.group;

	cout << "Number of courses(between 1 and 10): ";
	int numOfCourses = 0;
	cin >> numOfCourses;

	string course = "";
	double averageGrade = 0.0;
	for (int i = 0; i < numOfCourses * 2; i++)
	{
		if (i % 2 == 0)
		{
			cout << "Course: ";
			cin >> course;
			student.courses.insert(course);
		}

		else
		{
			cout << "Grade: ";
			string grade = "";
			cin >> grade;
			averageGrade += stod(grade) + 0.000;
			student.grades[course] = to_string(stod(grade) + 0.000);
		}
	}

	student.averageGrade = (averageGrade / numOfCourses);

	SaveFile(student);

	cout << "\nStudent has been registered successfully\n";
}