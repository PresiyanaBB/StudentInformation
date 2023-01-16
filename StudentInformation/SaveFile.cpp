#include "Student.cpp"
#include "Header.h";

void SaveFile(Student student)
{
	//fn - name - courses
	string group = "Groups/Group_" + student.group + ".txt";
	ofstream ofs;
	int counter = 1;
	ofs.open(group);

	string newStudent = student.fn + " - " + student.name + " - ";
	for(string c : student.courses)
	{
		if (student.courses.size() == counter)
		{
			newStudent += c;
		}
		else
			newStudent += c + ", ";

		counter++;		
	}

	ofs << newStudent;

	ofs.close();
}