#include "Header.h"

//string Courses[10] = {"Sport", "Math", "Science", "Algebra", "Geometry", "OOP", "Biology", "Chemistry", "History", "Geography" };

struct Student
{
	string name;
	string fn;
	string group;
	set<string> courses{};
	map<string, string> grades{};
	double averageGrade;
};
