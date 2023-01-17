#include "Header.h"

const int MAX_STUDENTS_IN_GROUP = 30;

void SortStudents()
{
	string groupNum;
	cout << "Choose group number(1 to 8): ";
	cin >> groupNum;
	string group = "Groups/Group_" + groupNum + ".txt";

	cout << "How would you like to sort them?\n" <<
		"1. Ascending\n" <<
		"2. Descending\n";

	int sortOption = 1;
	cin >> sortOption;

	string students[30]{};
	ifstream ifs;
	ifs.open(group);

	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, students[i]);
	}

	;
	//how do you want to sort then asc or desc
}