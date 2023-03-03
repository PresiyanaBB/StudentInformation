#include "../Headers/Header.h"

struct Student
{
	string firstName;
	string lastName;
	string fn;
	string group;
	set<string> courses{};
	map<string, string> grades{};
	double averageGrade;
};
