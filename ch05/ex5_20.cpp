#include<iostream>
#include<string>

using namespace std;

int main()
{
	string Nowstring, Prestring;
	bool  succession= true;
	cout << "请输入一组数据：" << endl;
	while (cin>>Nowstring)
	{
		if (Nowstring == Prestring)
		{
			cout << "连续出现的字符是；" << Nowstring << endl;
			break;
		}
		Prestring = Nowstring;
	}
	if (succession)
	{
		cout << "没有连续出现的字符串" << endl;
	}

	system("pause");
	return 0;
}
