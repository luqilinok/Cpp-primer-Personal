//说实话还是没有完全理解

#include<iostream>
#include<vector>
#include<list>
#include<string>

using std::vector;
using std::list;
using namespace std;

int main()
{
	list<int> ilist(5, 4);
	vector<int> ivec(5, 5);

	//从list<int>初始化vector<double>
	vector<double> dvec(ilist.begin(), ilist.end());
	for (auto i:ilist)
	{
		cout << i << " " << endl;
	}
	for (auto d : dvec)
	{
		cout << d << " ";
	}

	//从vector<int>初始化vector<double>
	vector<double> dvec2(ivec.begin(), ivec.end());
	for (auto i:ivec)
	{
		cout << i << " " << endl;
	}
	for (auto d : dvec2)
	{
		cout << d << " ";
	}

	system("pause");
	return 0;
}

