#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
	string words;
	deque<string> sdeque;
	while (cin>>words)
	{
		sdeque.push_back(words);
	}
	deque<string>::iterator it = sdeque.begin();
	for ( it; it < sdeque.end(); it++)
	{
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
