#include<iostream>
#include<string>

using namespace std;

int main()  //使用getline一次读入一整行
{
	string word;
	while (cin>>word)
	{
		cout << word << endl;
	}

	system("pause");
	return 0;
}
