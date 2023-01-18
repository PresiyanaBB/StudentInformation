#include "Header.h"
#include "Methods.h"

bool Menu()
{
	cout
		<< "Please select an option:\n" <<
		"1. Register new student\n" <<
		"2. Deregister student\n" <<
		"3. Sort students by faculty number or average grade\n" <<
		"4. Visualize students from group\n" <<
		"5. Exit\n\n" <<
		"Enter number of your option: ";

	int option = 5;
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
		return false;
		break;
	default:
		break;
	}

	cout << endl;
	return true;
}