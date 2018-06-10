#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdexcept>
#include<vector>
#include<map>

using namespace std;

map<string, string> buildMap(ifstream &map_file)  //读入给定文件，建立转换映射
{
	map<string, string> trans_map;   //保存转换规则
	string key;  //要转换的单词
	string value;  //替换后的内容

	while (map_file>>key && getline(map_file,value))  //读取第一个单词存入key中，行中剩余的内容存入value
	{
		if (value.size()>1)  //检查是否获得了1个以上的字符，如果是，调用substr跳过分隔单词及其转换短语之间的前导空格，并将得到的子字符串存入trans_map
		{
			trans_map[key] = value.substr(1);  //跳过前导空格
		}
		else
		{
			throw runtime_error("no rules for" + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)  //实际的转换工作；此部分是程序的核心
{
	auto map_it = m.find(s);  //如果单词在转换规则map中

	if (map_it!=m.end())
	{
		return map_it->second;   //使用替换短语
	}
	else
	{
		return s;   //否则返回原string
	}
}

void word_transform(ifstream &map_file, ifstream &input)   //管理整个过程
{
	auto trans_map = buildMap(map_file);  //保存转换规则
	cout << "Here is our transformation map: \n\n";
	for (auto entry:trans_map)  //输出转换规则表
	{
		cout << "key : " << entry.first << "\tvalue:" << entry.second << endl;
	}
	cout << "\n\n";

	string text;  //保存输入中的每一行
	while (getline(input,text))  //读取一行输入  
	{
		istringstream stream(text);  //读取每个单词
		string word;
		bool firstword = true;  //控制是否打印空格
		while (stream>>word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";  //在单词间打印一个空格，
			}
			//transform返回它的第一个参数或其转换之后的形式
			cout << transform(word, trans_map);  //打印输出
		}
		cout << endl;  //完成一行的转换
	}
}

int main(int argc, char *argv[])
{
	if (argc!=3)
	{
		throw runtime_error("wrong number of arguments");
	}

	ifstream map_file(argv[1]);  //检查是否有转换规则
	if (!map_file)
	{
		throw runtime_error("no transformation file");
	}
	ifstream input(argv[2]);  //检查是否有输入文件
	if (!input)
	{
		throw runtime_error("no input file"); 
	}

	word_transform(map_file, input);  //按照规则进行转换

	system("pause");
	return 0;
}
