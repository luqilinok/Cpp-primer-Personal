#include<iostream>
#include<string>

using namespace std;

int main(int argc, char *argv[])
{
	string str;
	for (int i = 0; i!= argc; ++i)
	{
		str += argv[i];  //+=运算符等价于str=str+argv[i]
	}

	cout << str << endl;

	system("pause");
	return 0;
}
