#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;
using namespace std::placeholders;

//书写一个函数，给定计数值、单词和结束符之后，判断计数值是否大于1.如果是，返回单词的复数形式，如果不是，返回单词的原型
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return(ctr> 1) ? word + ending : word;
}

void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());

	auto end_unique = unique(words.begin(), words.end());

	words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz)
{
	return s.size() > sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);  //将words按字典序排序，删除重复的单词
	for_each(words.begin(), words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
	//获取一个迭代器，指向最后一个满足size()>=sz的元素之后的位置
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
	//计算满足size()>=sz的元素数目
	auto count = wc - words.begin();
	cout << count << " " << make_plural(count, "words", "s") << "of length" << sz << "or longer" << endl;
	//打印长度大于给定值得单词，每个单词后面跟一个空格
	for_each(words.begin(), wc, [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输入文件失败！" << endl;
		exit(1);
	}

	vector<string> words;
	string word;
	while (in>>word)
	{
		words.push_back(word);
	}

	biggies(words, 6);

	system("pause");
	return 0;
}


