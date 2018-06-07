#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

void add_child(multimap<string, string> &families, const string &family, const string &child)
{
	families.insert({ family,child });
}

int main()
{
	multimap<string, string> families;

	add_child(families, "张", "强");
	add_child(families, "张", "刚");
	add_child(families, "王", "五");

	for (auto f : families)
	{
		cout << f.first << " 家的孩子" << f.second << endl;
	}

	system("pause");
	return 0;
}
