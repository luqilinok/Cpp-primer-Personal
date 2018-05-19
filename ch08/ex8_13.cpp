#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string& str)
{
	return isdigit(str[0]);    //isdigit是计算机C(C++)语言中的一个函数，主要用于检查其参数是否为十进制数字字符
}

string format(const string& str)
{
	return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);   //substr是C++语言函数，主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度
}

int main()
{
	ifstream in("phonenumber");
		if (!in)
		{
			cerr << "no phone numbers" << endl;
			return -1;
		}

		string line, word;          //分别保存来自输入的一行和单词
		vector<PersonInfo> people;  //保存来自输入的所有记录
		istringstream record;

		while (getline(cin, line))
		{
			PersonInfo info;   //创建一个保存此记录数据的对象
			record.clear();    //重复使用字节流时，每次都要调用clear
			record.str(line);  //将记录绑定到刚读入的行
			record >> info.name;  //读取名字
			while (record >> word)  //读取电话号码
			{
				info.phones.push_back(word);
			}
			people.push_back(info);
		}

		for (const auto &entry:people)   //对people中每一项
		{
			ostringstream formatted, badNums;  //每个循环步创建的对象
			for (const auto &nums:entry.phones)   //对每个数
			{
				if (!valid(nums))
				{
					badNums << " " << nums;  //将数的字符串形式存入badNums
				}
				else
				{
					formatted << " " << format(nums);  //将格式化的字符串“写入”formatted 
				}
			}
			if (badNums.str().empty())  //没有错误的数
			{
				cout << entry.name << " " << formatted.str() << endl;  //打印名字和格式化的数
			}
			else  //否则，打印名字和错误的数
			{
				cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << endl;
			}
		}
		system("pause");
		return 0;
}
