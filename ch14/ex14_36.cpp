#include<vector>
#include"ex14_36.h"

using namespace std;

void testReadString()
{
	ReadString rs;
	vector<string> vec;
	while (true)
	{
		string line = rs();
		if (!line.empty())
		{
			vec.push_back(line);
		}
		else
		{
			break;
		}
	}
}
