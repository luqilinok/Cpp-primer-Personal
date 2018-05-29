#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
	string s = "acenmorsuvwxz";
	ifstream in(argv[1]);
	string str;
	in >> str;  //单词文件写入
	cout << "原字符串为:" << str << endl;

	unsigned pos1 = 0;
	unsigned pos2 = 0;
	unsigned pos3 = 0;
	unsigned _length = 0;
	
	while ((pos1 = str.find_first_of(s, pos1)) != string::npos)  //找到第一个不出头字符串
	{
		pos2 = pos1;
		if ((pos2=str.find_first_not_of(s,pos2))!=string::npos)  //从第一个不出头字符串找到第一个出头的字符串
		{
			if (pos2-pos1>=_length)  //找出最大长度并记录此区间的首位置
			{
				_length = pos2 - pos1;
				pos3 = pos1;
			}
		}
		++pos1;
	}
	string _string = str.substr(pos3, _length);  //拷贝从pos3开始加上_length长度的字符串
	cout << "最长不出头串为：" << _string << endl;
	system("pause");
	return 0;
}
