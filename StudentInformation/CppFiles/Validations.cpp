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
* <helper file that validates user inputs>
*
*/

#include "../Headers/Header.h"
#include "Constants.cpp"
#include "Student.cpp"

string ValidateGroup(string& groupNumber)
{
	string groupNum = "1";
	string group = "Groups/Group_" + groupNum + ".txt";

	while (true)
	{
		cout << "Enter group number(from 1 to 8): ";
		cin >> groupNum;
		group = "Groups/Group_" + groupNum + ".txt";

		try
		{
			if (stoi(groupNum) < 1 || stoi(groupNum) > 8)
				continue;

			groupNumber = groupNum;
			break;
		}
		catch (const std::exception&)
		{
			continue;
		}
	}

	return group;
}

bool ValidateOptions(int& option)
{
	try
	{
		string optioninput = "";
		cin >> optioninput;
		option = stoi(optioninput);
	}
	catch (const std::exception&)
	{
		system("cls");
		return false;
	}

	return true;
}

void ValidateNumberOfCourses(int& numberOfCourses)
{
	string numOfCoursesInput = "";

	while (true)
	{
		cout << "Number of courses(between " << MIN_COURSES << " and " << MAX_COURSES << "): ";
		cin >> numOfCoursesInput;

		try
		{
			numberOfCourses = stoi(numOfCoursesInput);
			if (numberOfCourses < MIN_COURSES || numberOfCourses > MAX_COURSES)
				continue;
		}
		catch (const std::exception&)
		{
			continue;
		}

		break;
	}
}

void ValidateCourses(string& course, set<string>& courses)
{
	while (true)
	{
		cout << "Course: ";
		cin >> course;
		if (find(begin(Courses), end(Courses), course) == end(Courses))
		{
			cout << "Invalid course\n";
			continue;
		}
		courses.insert(course);
		break;
	}
}

void ValidateGrade(string& grade)
{
	while (true)
	{
		cout << "Grade: ";
		cin >> grade;
		try
		{
			if (stod(grade) < 2.0 || stod(grade) > 6.00)
				continue;
			break;
		}
		catch (const std::exception&)
		{
			continue;
		}
	}
}

bool ValidateCountOfStudents(string group)
{
	ifstream ifs;
	ifs.open(group);
	string student = "";
	int countOfStudents = 0;

	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, student);
		if (student == "")
			continue;

		countOfStudents++;
	}

	ifs.close();

	return (countOfStudents >= MAX_STUDENTS_IN_GROUP);
}
