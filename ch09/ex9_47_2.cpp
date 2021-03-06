#include<iostream>
#include<string>

using namespace std;
using std::string;

int main()
{
	string numbers{ "0123456789" };
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ" };
	string str{ "ab2c3d7R4E6" };

	cout << "numeric characters: ";
	for (int pos = 0; (pos=str.find_first_not_of(alphabet,pos))!=string::npos ; pos++)
	{
		cout << str[pos] << " ";
	}
	cout << "\nalphabetic characters: ";
	for (int pos=0;(pos=str.find_first_not_of(numbers,pos))!=string::npos;pos++)
	{
		cout << str[pos] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
