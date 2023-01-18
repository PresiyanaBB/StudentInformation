#include "Methods.h"
#include <iomanip>
#include "Constants.cpp"
#include "Validation.h"

const string Courses[MAX_COURSES] = { "Sport", "Math", "Science", "Algebra", "Geometry", "OOP", "Biology", "Chemistry", "History", "Geography" };

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
	Student student;

	cout << "Name: ";
	cin >> student.name;

	cout << "Faculty number: ";
	cin >> student.fn;

	string group = ValidateGroup(student.group);

	cout << "Number of courses(between " << MIN_COURSES << " and " << MAX_COURSES << "): ";
	int numOfCourses = 0;
	cin >> numOfCourses;

	if (numOfCourses < MIN_COURSES || numOfCourses > MAX_COURSES)
		return;

	showCourses();
	string course = "";
	double averageGrade = 0.0;
	for (int i = 0; i < numOfCourses * 2; i++)
	{
		if (i % 2 == 0)
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
				student.courses.insert(course);
				break;
			}
		}

		else
		{
			string grade = "";
			while (true)
			{
				cout << "Grade: ";
				cin >> grade;
				try
				{
					if (stod(grade) < 0.0 || stod(grade) > 6.00)
						continue;
					break;
				}
				catch (const std::exception&)
				{
					continue;
				}
			}
			
			averageGrade += stod(grade) + 0.000;
			student.grades[course] = to_string(stod(grade) + 0.000);
		}
	}

	student.averageGrade = (averageGrade / numOfCourses);

	SaveFile(student);

	system("cls");

	cout << "Student has been registered successfully\n";
}