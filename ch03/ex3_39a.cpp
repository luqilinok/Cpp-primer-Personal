#include<iostream>
#include<string>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	//using string
	string s1("Mooophy"), s2("Pezy");
	if (s1 == s2)
	{
		cout << "same strings" << endl;
	}
	else if (s1>s2)
	{
		cout << "Mooophy>Pezy" << endl;
	}
	else
	{
		cout << "Mooophy<Pezy" << endl;
	}

	system("pause");
	return 0;
}
