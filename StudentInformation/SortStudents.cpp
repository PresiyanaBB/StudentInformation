#include "Header.h"
#include "Constants.cpp"
#include <algorithm>

template <typename T>

//sort for grades and fn
void bubbleSort(T criteria[], int n,string studentInfo[])
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (criteria[j] > criteria[j + 1])
			{
				swap(studentInfo[j], studentInfo[j + 1]);
				swap(criteria[j], criteria[j + 1]);
			}
}

string getFacultyNumber(string fullInfo)
{
	string fn = "";
	for (int i = 0; fullInfo[i] != ' '; i++)
		fn += fullInfo[i];

	return fn;
}

void SortStudents()
{
	string groupNum;
	cout << "Choose group number(1 to 8): ";
	cin >> groupNum;
	string group = "Groups/Group_" + groupNum + ".txt";

	cout << "How would you like to sort them?\n" <<
		"1. Ascending, 2. Descending: ";

	int sortOptionAscDesc = 1;
	cin >> sortOptionAscDesc;

	cout << "How would you like to sort them?\n" <<
		"1. By average grade, 2. By faculty number: ";

	int sortOptionFnGrade = 1;
	cin >> sortOptionFnGrade;

	if (sortOptionAscDesc < 1 || sortOptionAscDesc > 2)
	{
		cout << endl;
		return;
	}

	string studentsInfo[MAX_STUDENTS_IN_GROUP]{};
	double grades[MAX_STUDENTS_IN_GROUP]{};
	string facultyNumbers[MAX_STUDENTS_IN_GROUP]{};

	ifstream ifs;
	ifs.open(group);
	int countOfStudents = 0;

	//read student information from file
	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, studentsInfo[i]);
		if (studentsInfo[i] == "")
			continue;
		grades[i] = stod(studentsInfo[i].substr(studentsInfo[i].size() - 4));
		facultyNumbers[i] = getFacultyNumber(studentsInfo[i]);
		countOfStudents++;
	}

	if (sortOptionFnGrade == 1)
		bubbleSort(grades,countOfStudents,studentsInfo);

	if (sortOptionFnGrade == 2)
		bubbleSort(facultyNumbers, countOfStudents, studentsInfo);

	if (sortOptionAscDesc == 2) //descending
	{
		string temp;
		for (int i = 0, j = countOfStudents - 1; i < countOfStudents / 2; i++, j--)
		{
			temp = studentsInfo[i];
			studentsInfo[i] = studentsInfo[j];
			studentsInfo[j] = temp;
		}
	}

	ifs.close();

	ofstream ofs;
	ofs.open(group);

	for (int i = 0; i < countOfStudents; i++)
		ofs << studentsInfo[i] << endl;

	ofs.close();
}