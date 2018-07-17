#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main()
{
	string zip = "(\\d{5})((-?)((-?)(\\d{4}))?";
	regex r(zip);
	string s;
	string fmt = "$1-$2";

	while (getline(cin, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; it++)
		{
			if ((*it)[2].matched && (*it)[2].str()[0] != '-')
			{
				cout << (*it).format(fmt) << endl;
			}
			else
			{
				cout << (*it).str() << endl;
			}
		}
	}

	system("pause");
	return 0;
}
