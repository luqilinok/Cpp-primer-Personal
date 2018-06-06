#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

string &trans(string &s)     //对string进行大小写转换，并且删除标点符号
{
	for (int p = 0; p < s.size(); p++)   
	{
		if (s[p]>='A'&&s[p]<='Z')
		{
			s[p] -= ('A' - 'a');
		}
		else if (s[p]==','||s[p]=='.')
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
		exit(1);
	}

	map<string, list<int>> word_lineno;  //单词到行号的映射
	string line;
	string word;
	int lineno = 0;
	while (getline(in,line))   //读取一行
	{
		lineno++;  //行号递增
		istringstream l_in(line);  //构造字符流串
		while (l_in>>word)
		{
			trans(word);
			word_lineno[word].push_back(lineno);  //添加行号
		}
	}
	for (const auto &w:word_lineno)  //打印单词行号
	{
		cout << w.first << "所在行：";
		for (auto const &i:w.second)
		{
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
	
}
