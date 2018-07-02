#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class StrLenBetween
{
public:
	StrLenBetween(int minLen, int maxLen) :minLen(minLen), maxLen(maxLen) {}
	bool operator()(const string &str)
	{
		return str.length >= minLen && str.length <= maxLen;
	}

private:
	int minLen;
	int maxLen;
};

class StrNotShorterThan
{
public:
	StrNotShorterThan(int len) :minLen(len) {}
	bool operator()(const string &str) { return str.length() >= minLen; }

private:
	int minLen;
};

void ReadStr(istream &is, vector<string> &vec)
{
	string word;
	while (is >> word)
	{
		vec.push_back(word);
	}
}

int main()
{
	vector<string> vec;
	ReadStr(cin, vec);

	StrLenBetween slenBetween(1, 9);
	StrNotShorterThan sNotShorterThan(10);

	cout << "len 1-9: " << count_if(vec.begin(), vec.end(), slenBetween) << endl;
	cout << "len>=10 " << count_if(vec.begin(), vec.end(), sNotShorterThan) << endl;

	system("pause");
	return 0;
}
