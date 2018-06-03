#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;
using namespace std::placeholders;

//书写一个函数，给定计数值、单词和结束符之后，判断计数值是否大于1.如果是，返回单词的复数形式，如果不是，返回单词的原型
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return(ctr> 1) ? word + ending : word;
}

//按字典序排序，并使得每个单词只出现一次
void elimDups(vector<string> &words)
{
	sort(words.begin(), words.end());  //按字典序排序words
	auto end_unique = unique(words.begin(), words.end());  //重拍输入范围，使得每个单词只出现一次
	words.erase(end_unique, words.end());
}

//比较一个string和一个给定大小
bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}

//求大于等于一个给定长度的单词有多少，另外修改输出，使程序只打印大于等于给定长度的单词
void biggies(vector<string> &words, vector<string>::size_type sz)
{
	elimDups(words);
	for_each(words.begin(), words.end(), [](const string &s) {cout << s << " "; });  //使用for_each算法接受一个可调用参数，并对输入序列中的每个元素调用此对象
	cout << endl;
	//获取一个迭代器，指向最后一个满足size()>=sz的元素之后的位置(用partition算法)
	auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));   //bind调用中只有一个占位符_1，且占位符出现在arg_list的第一个位置，表示此参数对应check_size的第一个参数--const string &s。此bind调用生成一个可调用对象，将check_size的第二个参数绑定到sz的值，当find_if对words中的string调用这个对象时，这些对象会调用check_size，将给定的string和sz传递给它
	//计算满足size()>=sz的元素的数目
	auto count = wc - words.begin();
	//打印长度大于等于给定值的单词，每个单词后面接一个空格
	cout << count << " " << make_plural(count, "words", "s") << "of length" << sz << "or longer" << endl;
	for_each(words.begin(), wc, [](const string &s) {cout << s << " "; });  //使用for_each算法接受一个可调用参数，并对输入序列中的每个元素调用此对象,本段程序的意思是从words.begin()开始，到指向最后一个满足size()>=sz的元素之后的位置中间，所有的元素都打印s
	cout << endl;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输出文件失败！" << endl;
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
