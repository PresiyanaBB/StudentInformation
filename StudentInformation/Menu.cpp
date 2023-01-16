#include "Header.h"
#include "Methods.h"

void Menu()
{
	cout
		<< "Please select an option:\n" <<
		"1. Register new student\n" << //max 10 courses
		"2. Deregister student\n" <<
		"3. Sort students by faculty number and average grade\n" << //ascending or descending
		"4. Visualize students from group\n" <<
		"5. Exit\n\n" <<
		"Enter number of your option: ";

	int option = 1;
	cin >> option;

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
		return;
		break;
	default:
		break;
	}

	Menu();
}