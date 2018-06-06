#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<string> unique_words;
	string word;

	while (cin>>word)
	{
		
		if (find(unique_words.begin(),unique_words.end(),word)==unique_words.end())
		{
			unique_words.push_back(word);
		}
	}
	for (const auto &w : unique_words)
	{
		cout << w << " ";
	}

	system("pause");
	return 0;
}
