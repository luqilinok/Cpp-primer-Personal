#include<iostream>
#include<string>
#include<list>

using namespace std;

int main()
{
	string words;
	list<string> slist;
	while (cin >> words)
	{
		slist.push_back(words);
	}
	list<string>::iterator it = slist.begin();
	for (it;it!=slist.end();it++)
	{
		cout << *it << endl;
	}
	system("pause");
	return 0;
}
