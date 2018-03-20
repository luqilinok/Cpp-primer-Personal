#include<iostream>
#include<string>

using namespace std;

int main()  //使用getline一次读入一整行
{
	string line;
	//循环读入，每次读入一整行，直至文件结束活遇到异常输入
	while (getline(cin,line))
	{
		cout << line << endl;
	}

	system("pause");
	return 0;
}
