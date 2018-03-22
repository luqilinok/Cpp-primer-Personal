#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (auto &c : s)
	{
		c = 'X';
	}
	cout << s << endl;

	system("pause");
	return 0;
}
