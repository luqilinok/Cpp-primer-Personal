#include<iostream>
#include<vector>
#include<list>
#include<string>

using std::vector;
using std::list;
using namespace std;

int main()
{
	list<string> names;
	vector<const char*> oldstyle;
	names.assign(oldstyle.cbegin(), oldstyle.cend());

	system("pause");
	return 0;
}

