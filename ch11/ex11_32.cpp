#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	multimap<string, string> authors{
		{ "alan", "DMA" },
	{ "pezy", "LeetCode" },
	{ "alan", "CLRS" },
	{ "wang", "FTP" },
	{ "pezy", "CP5" },
	{ "wang", "CPP-Concurrency" }
	};
	
	map<string, multiset<string>> order_authors;
	for (const auto &author:authors)
	{
		order_authors[author.first].insert(author.second);
	}
	for (const auto &author:order_authors)
	{
		cout << author.first << ":";
		for (const auto &bookname : author.second)
		{
			cout << bookname << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
