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