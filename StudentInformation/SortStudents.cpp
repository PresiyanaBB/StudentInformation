#include "Header.h"
#include "Constants.cpp"

void bubbleSort(double grades[], int n,string studentInfo[])
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (grades[j] > grades[j + 1])
			{
				swap(studentInfo[j], studentInfo[j + 1]);
				swap(grades[j], grades[j + 1]);
			}
}

//TODO: sort by faculty number

void SortStudents()
{
	string groupNum;
	cout << "Choose group number(1 to 8): ";
	cin >> groupNum;
	string group = "Groups/Group_" + groupNum + ".txt";

	cout << "How would you like to sort them?\n" <<
		"1. Ascending, 2. Descending: ";

	int sortOption = 1;
	cin >> sortOption;

	if (sortOption < 1 || sortOption > 2)
	{
		cout << endl;
		return;
	}

	string studentsInfo[MAX_STUDENTS_IN_GROUP]{};
	double grades[MAX_STUDENTS_IN_GROUP]{};

	ifstream ifs;
	ifs.open(group);
	int countOfStudents = 0;

	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, studentsInfo[i]);
		if (studentsInfo[i] == "")
			continue;
		grades[i] = stod(studentsInfo[i].substr(studentsInfo[i].size() - 4));
		countOfStudents++;
	}

	bubbleSort(grades,countOfStudents,studentsInfo);

	if (sortOption == 2)
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