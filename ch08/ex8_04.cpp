#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ifstream in("data");   //打开文件
	if (!in)
	{
		cerr << "无法打开数据文件" << endl;
		return -1;
	}
	string line;
	vector<string> words; 
	while (getline(in,line))     //从文件中读取一行
	{
		words.push_back(line);
	}
	in.close();   //输入完毕，关闭文件

	vector<string>::const_iterator it = words.begin();
	while (it!=words.end())   //遍历vector
	{
		cout << *it << endl;    //输出vector中的元素
		++it;
	}
	
	system("pause");
	return 0;
}
