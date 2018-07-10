#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

template<typename C>

void print(const C &c)
{
	for (auto i = c.begin(); i != c.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int main()
{
	string s = "hello";
	print(s);

	vector<int> vi = { 0,2,4,6,8 };
	print(vi);

	list<string> ls = { "hel","lo","!" };
	print(ls);

	system("pause");
	return 0;
}
