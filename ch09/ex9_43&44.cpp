#include<iostream>
#include"demo.h"

using namespace std;

int main()
{
	string s{ "To drive straight thru is a foolish,tho courageous act." };
	replace_with(s, "tho", "though");
	replace_with(s, "thru", "through");
	cout << s << endl;

	system("pause");
	return 0;
}
