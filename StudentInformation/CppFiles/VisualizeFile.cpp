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
* <file that visualizes students on the console>
*
*/

#include "../Headers/Header.h"
#include "../Headers/Validation.h"

void VisualizeFile()
{
	string currentStudent;
	string groupNumber = "";
	string group = ValidateGroup(groupNumber);
	
	ifstream ifs;
	ifs.open(group);

	cout << endl;
	while (!ifs.eof())
	{
		getline(ifs,currentStudent);
		cout << currentStudent << endl;
	}

	ifs.close();
}