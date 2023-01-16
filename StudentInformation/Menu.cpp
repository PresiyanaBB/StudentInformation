#include "Header.h"
#include "Methods.h"

void Menu()
{
	Student student;
	student.fn = "fn_34567890";
	student.group = "3";
	student.name = "pesho";
	student.courses = { "Math","OOP"};

	SaveFile(student);

	cout
		<< "Please select an option:\n" <<
		"1. Register new student\n" <<
		"2. Deregister student\n" <<
		"3. Sort students by faculty number and average grade\n" << //ascending or descending
		"4. Visualize students from group\n\n" <<
		"Enter number of your option: ";
	//always save file

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
	default:
		break;
	}
}