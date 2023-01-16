#include "Header.h";

enum Courses { Sport, Math, Science, Algebra, Geometry, OOP, Biology, Chemistry, History, Geography };

struct Student
{
	string name;
	string fn;
	int group;
	map<Courses, double> grades;
	double averageGrade;
};
