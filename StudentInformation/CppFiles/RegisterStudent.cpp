/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Presiyana Borisova
* @idnumber 3MI0600240 @compiler VisualStudio
*
* <file that registers new student>
*
*/

#include "../Headers/Methods.h"
#include <iomanip>
#include "Constants.cpp"
#include "../Headers/Validation.h"

void showCourses()
{
	cout << "List of available courses: ";

	for (int i = 0; i < MAX_COURSES; i++)
	{
		cout << Courses[i];
		if (i != MAX_COURSES - 1) cout << ", ";
	}

	cout << endl;
}

void RegisterStudent()
{
	cin.ignore();
	Student student;

	cout << "Name(first name, last name): ";
	cin >> student.firstName;
	cin >> student.lastName;

	cout << "Faculty number: ";
	cin >> student.fn;

	string group = ValidateGroup(student.group);

	if (ValidateCountOfStudents(group))
	{
		system("cls");
		cout << "This group is already full\n"; 
		return;
	}

	int numOfCourses = 0;	
	ValidateNumberOfCourses(numOfCourses);

	showCourses();
	string course = "";
	double averageGrade = 0.0;

	for (int i = 0; i < numOfCourses * 2; i++)
	{
		if (i % 2 == 0)
		{
			ValidateCourses(course, student.courses);
		}

		else
		{
			string grade = "";
			ValidateGrade(grade);
			
			averageGrade += stod(grade) + 0.000;
			student.grades[course] = to_string(stod(grade) + 0.000);
		}
	}

	student.averageGrade = (averageGrade / numOfCourses);

	SaveFile(student);

	system("cls");

	cout << "Student has been registered successfully\n";
}