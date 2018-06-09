#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	multimap<string, string> authors{
	{"alan","DMA"},
	{"pezy", "Leetcode"},
	{"alan","CLRS"},
	{"wang","FTP"},
	{"pezy","CP5"},
	{"wang","CPP-Concurrency"}
	};

	string author = "pezy";
	string bookname = "CP5";

	auto found = authors.find(author);
	auto count = authors.count(author);
	while (count)
	{
		if (found->second==bookname)
		{
			authors.erase(found);
			break;
		}
		++found;
		--count;
	}
	for (const auto &author:authors)
	{
		cout << author.first << " " << author.second << endl;
	}

	system("pause");
	return 0;
}
