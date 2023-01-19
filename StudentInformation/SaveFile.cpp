#include "Student.cpp"
#include "Header.h";

void SaveFile(Student student)
{
	//fn - name - courses(grades) - average grade
	string group = "Groups/Group_" + student.group + ".txt";
	ofstream ofs;
	int counter = 1;
	ofs.open(group, ios::app);

	string newStudent = student.fn + " - " + student.firstName + " " + student.lastName + " - ";
	for (string c : student.courses)
	{
		if (student.courses.size() == counter)
			newStudent += c + '(' + student.grades[c].substr(0, 4) + ')' + " - ";

		else
			newStudent += c + '(' + student.grades[c].substr(0, 4) + "), ";

		counter++;
	}

	ofs << newStudent << (to_string(student.averageGrade + 0.000)).substr(0, 4) << endl;

	ofs.close();
}