#include "Header.h";

void VisualizeFile()
{
	cout << "Enter group number(from 1 to 8): ";
	string groupNum;
	string currentStudent;

	cin >> groupNum;
	string group = "Groups/Group_" + groupNum + ".txt";
	ifstream ifs;
	ifs.open(group);

	while (!ifs.eof())
	{
		getline(ifs,currentStudent);
		cout << currentStudent << endl;
	}

	ifs.close();
}