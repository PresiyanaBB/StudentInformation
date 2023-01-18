#include "Header.h";

void VisualizeFile()
{
	string groupNum = "1";
	string currentStudent;
	string group = "Groups/Group_" + groupNum + ".txt";

	while (true)
	{
		cout << "Enter group number(from 1 to 8): ";
		cin >> groupNum;
		group = "Groups/Group_" + groupNum + ".txt";

		try
		{
			stoi(groupNum);
			if (stoi(groupNum) < 1 || stoi(groupNum) > 8)
				continue;
			break;
		}
		catch (const std::exception&)
		{
			continue;
		}
	}
	
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