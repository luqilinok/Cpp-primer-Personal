#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>

using namespace std;

inline void output_words(vector<string> &words)
{
	for (auto iter = words.begin(); iter !=words.end(); iter++)
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

	output_words(words);
}

int main()
{

	vector<string> words;
	string word;
	while (cin>>word)
	{
		words.push_back(word);
	}

	elimDups(words);



	system("pause");
	return 0;
}
