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
* <Main menu>
*
*/

#include "../Headers/Header.h"
#include "../Headers/Methods.h"
#include "../Headers/Validation.h"

bool Menu()
{
	cout
		<< "------------------------MENU------------------------\n\n" <<
		"Please select an option:\n" <<
		"1. Register new student\n" <<
		"2. Deregister student\n" <<
		"3. Sort students by faculty number or average grade\n" <<
		"4. Visualize students from group\n" <<
		"5. Exit\n\n" <<
		"Enter number of your option: ";

	int option = 5;

	if (!ValidateOptions(option))
	{
		system("cls");
		return true;
	}

	switch (option)
	{
	case 1:
		RegisterStudent();
		break;
	case 2:
		DeregisterStudent();
		break;
	case 3:
		SortStudents();
		break;
	case 4:
		VisualizeFile();
		break;
	case 5:
		return false;
		break;
	default:
		system("cls");
		return true;
		break;
	}

	cout << endl;
	return true;
}