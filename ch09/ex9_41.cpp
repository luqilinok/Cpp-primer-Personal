#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<char> v{ 'p','e','z','y' };
	string str(v.cbegin(), v.cend());
	cout << str << endl;

	system("pause");
	return 0;
}
