#include "Header.h"

string ValidateGroup(string& groupNumber)
{
	string groupNum = "1";
	string group = "Groups/Group_" + groupNum + ".txt";

	while (true)
	{
		cout << "Enter group number(from 1 to 8): ";
		cin >> groupNum;
		group = "Groups/Group_" + groupNum + ".txt";

		try
		{
			if (stoi(groupNum) < 1 || stoi(groupNum) > 8)
				continue;

			groupNumber = groupNum;
			break;
		}
		catch (const std::exception&)
		{
			continue;
		}
	}

	return group;
}