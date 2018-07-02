#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class IsShorter
{
public:
	bool operator()(const string &s1, const string &s2) { return s1.size() < s2.size(); }
};

class NotShorterThan
{
public:
	NotShorterThan(int len) :minLen(len) {}
	bool operator()(const string &str) { return str.size() >= minLen; }
private:
	int minLen;
};

class PrintString
{
public:
	void operator()(const string &str)
	{
		cout << str << " ";
	}
};

void elimDups(vector<string> &words)
{
	//按字典序排序words，以便查找重复单词
	sort(words.begin(), words.end());
	//unique重排输入范围,使得每个单词只出现一次
	//排列在范围的前部，返回指向不重复区域之后的一个位置的迭代器
	auto end_unique = unique(words.begin(), words.end());
	//使用向量操作erase删除重复单词
	words.erase(end_unique, words.end());
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return(ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);

	IsShorter is;
	stable_sort(words.begin(), words.end(), is);

	NotShorterThan nst(sz);
	auto wc = find_if(words.begin(), words.end(), nst);
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "words", "s") << "of length" << sz << " or longer " << endl;

	PrintString ps;
	for_each(wc, words.end(), ps);
	cout << endl;
}
