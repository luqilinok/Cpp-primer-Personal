#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ifstream in("data");
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}
	string line;
	vector<string> words;
	while (in>>line)    //getline是读取一整行，而本题要求将每个单词作为一个独立的元素进行存储
	{
		words.push_back(line);
	}
	in.close();
	vector<string>::const_iterator it = words.begin();
	while (it!=words.end())
	{
		cout << *it << endl;
		++it;
	}

	system("pause");
	return 0;
}
