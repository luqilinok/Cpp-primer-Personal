#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	while (getline(cin, s))
	{
		cout << regex_replace(s, r, fmt) << endl;
	}

	system("pause");
	return 0;
}
