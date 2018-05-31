#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>

using namespace std;

inline void output_words(vector<string> &words)
{
	for (auto iter = words.begin(); iter != words.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{

	vector<string> words;
	string word;
	while (cin >> word)
	{
		words.push_back(word);
	}

	elimDups(words);
	stable_sort(words.begin(), words.end(), isShorter);
	for (const auto  &s:words)
	{
		cout << s << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}
