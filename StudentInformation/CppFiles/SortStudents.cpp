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
* <file that sorts students>
*
*/

#include "Constants.cpp"
#include "../Headers/Header.h"
#include "../Headers/Validation.h"

template <typename T>

//sort by grades or fn
void bubbleSort(T criteria[], int n, string studentInfo[])
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
	string groupNumber = "";
	string group = "";
	int numberOfGroups = 1;

	group = ValidateGroup(groupNumber);

	cout << "How would you like to sort them?\n" <<
		"1. Ascending, 2. Descending: ";

	string sortOptionAscDesc = "1";
	cin >> sortOptionAscDesc;

	if (sortOptionAscDesc.substr(0, 1) != "1" && sortOptionAscDesc.substr(0, 1) != "2")
		sortOptionAscDesc.substr(0, 1) = "1"; //default sorting is ascending

	cout << "How would you like to sort them?\n" <<
		"1. By average grade, 2. By faculty number: ";

	string sortOptionFnGrade = "1";
	cin >> sortOptionFnGrade;

	if (sortOptionFnGrade.substr(0, 1) != "1" && sortOptionFnGrade.substr(0, 1) != "2")
		sortOptionFnGrade = "1"; //default sorting is by average grade

	system("cls");

	cout << "Students have been sorted successfully." << endl;

	string studentsInfo[MAX_STUDENTS_IN_GROUP + 1]{};
	double grades[MAX_STUDENTS_IN_GROUP + 1]{};
	string facultyNumbers[MAX_STUDENTS_IN_GROUP + 1]{};

	ifstream ifs;
	ifs.open(group);
	int countOfStudents = 0;

	//read student information from file
	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, studentsInfo[i]);
		if (studentsInfo[i] == "")
		{
			i--; continue;
		}
		grades[i] = stod(studentsInfo[i].substr(studentsInfo[i].size() - 4));
		facultyNumbers[i] = getFacultyNumber(studentsInfo[i]);
		countOfStudents++;
	}

	if (sortOptionFnGrade == "1") //by average grade
		bubbleSort(grades, countOfStudents, studentsInfo);

	if (sortOptionFnGrade == "2") //by faculty number
		bubbleSort(facultyNumbers, countOfStudents, studentsInfo);

	if (sortOptionAscDesc == "2") //descending
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