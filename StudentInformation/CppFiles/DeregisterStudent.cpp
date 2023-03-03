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
* <file that deregisters student and removes it from file>
*
*/

#include "Constants.cpp"
#include "../Headers/Header.h"
#include "../Headers/Validation.h"

void DeregisterStudent()
{
	string groupNumber = "";
	string group = ValidateGroup(groupNumber);

	string fn = "";
	cout << "Enter faculty number: ";
	cin >> fn;

	string studentsInfo[MAX_STUDENTS_IN_GROUP]{};
	string facultyNumbers[MAX_STUDENTS_IN_GROUP]{};

	ifstream ifs;
	ifs.open(group);
	int indexOfStudent = 0;
	int countOfStudents = 0;

	for (int i = 0; !ifs.eof(); i++)
	{
		getline(ifs, studentsInfo[i]);
		if (studentsInfo[i] == "")
			continue;

		int interval = studentsInfo[i].find(" ");
		facultyNumbers[i] = studentsInfo[i].substr(0, interval);

		if (facultyNumbers[i] == fn)
			indexOfStudent = i;

		countOfStudents++;
	}

	ifs.close();

	ofstream ofs;
	ofs.open(group);

	for (int i = 0; i < countOfStudents; i++)
	{
		if (i == indexOfStudent)
			continue;

		else
			ofs << studentsInfo[i] << endl;
	}

	ofs.close();
}