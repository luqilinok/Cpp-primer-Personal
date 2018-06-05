#include<iostream>
#include<fstream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

string &trans(string &s)
{
	for (int p=0;p<s.size();p++)
	{
		if (s[p]>='A'&& s[p]<='Z')
		{
			s[p] -= ('A' - 'a');  //将大写转换为小写（减去A，加上a），等价于s[p]=s[p]-('A'-'a')
		}
		else if(s[p]==','||s[p]==',')   //如果出现标点符号，将其删除
		{
			s.erase(p, 1);
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输出文件失败！" << endl;
		return -1;
	}
	map<string,size_t> word_count;
	string word;
	while (in>>word)
	{
		++word_count[word];
	}
	for (const auto &w:word_count)
	{
		cout << w.first << " occurs" << w.second << ((w.second > 1) ? " times" : " time") << endl;
	}
}
