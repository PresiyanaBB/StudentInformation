#include "Header.h"

struct Student
{
	string name;
	string fn;
	string group;
	set<string> courses{};
	map<string, string> grades{};
	double averageGrade;
};
