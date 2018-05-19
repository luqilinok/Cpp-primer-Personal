#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{
	string line, word;          //分别保存来自输入的一行和单词
	vector<PersonInfo> people;  //保存来自输入的所有记录
	istringstream record;
	
	while (getline(cin,line))
	{
		PersonInfo info;   //创建一个保存此记录数据的对象
		record.clear();    //重复使用字节流时，每次都要调用clear
		record.str(line);  //将记录绑定到刚读入的行
		record >> info.name;  //读取名字
		while (record>>word)  //读取电话号码
		{
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	system("pause");
	return 0;
}
