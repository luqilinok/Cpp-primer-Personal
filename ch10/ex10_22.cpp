#include<iostream>
#include<fstream>
#include<functional>
#include<vector>
#include<algorithm>


using namespace std;
using namespace std::placeholders;

//书写一个函数，给定计数值、单词和结束符之后，判断计数值是否大于1.如果是，返回单词的复数形式，如果不是，返回单词的原型
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return(ctr> 1) ? word + ending : word;
}

inline void output_words(vector<string> &words)  //输出单词
{
	for (auto iter=words.begin();iter!=words.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

bool check_size(const string &s, string::size_type sz)   //比较一个string和一个给定大小
{
	return s.size() >= sz;
}

void biggies(vector<string> &words, vector<string>::size_type sz)   //求大于等于一个给定长度的单词有多少，另外修改输出，使程序只打印大于等于给定长度的单词
{
	output_words(words);

	//统计满足size()>=sz的元素的个数
	auto bc = count_if(words.begin(), words.end(), bind(check_size, _1, sz));

	cout << bc << " " << make_plural(bc, "words", "s") << "of length" << sz << "of longer" << endl;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输入文件失败" << endl;
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

