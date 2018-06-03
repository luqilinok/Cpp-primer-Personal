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

bool check_size(const string &s, string::size_type sz)
{
	return s.size() <= sz;
}

void biggies(vector<int> &vc, const string &s)   //求大于等于一个给定长度的单词有多少，另外修改输出，使程序只打印大于等于给定长度的单词
{
	//查找第一个大于等于s长度的数值
	auto p = find_if(vc.begin(), vc.end(), bind(check_size, s, _1));

	//打印结果
	cout << "第" << p - vc.begin() + 1 << "个数" << *p << "大于等于" << s << "的长度" << endl;
}

int main(int argc,char *argv[])
{
	vector<int> vc = { 1,2,3,4,5,6,7,8,9 };
	
	biggies(vc, "hello");
	biggies(vc,"everyone");
	biggies(vc, "!");

	system("pause");
	return 0;
}
