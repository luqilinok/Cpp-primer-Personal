#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return(ctr> 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());  //unique重排输入范围，使得每个单词只出现一次

	words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  //将words按字典序排序，删除重复的单词

	stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size(); });

	auto bc = count_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz; });

	auto count = words.end() - bc;   //计算满足size>=sz的元素数目
	cout << bc << " " << make_plural(bc, "word", "s") << "of length" << sz << "or longer" << endl;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输出文件失败!" << endl;
		exit(1);
	}

	vector<string> words;
	string word;
	while (cin >> word)
	{
		words.push_back(word);

		biggies(words, 6);

		system("pause");
		return 0;
	}
}
