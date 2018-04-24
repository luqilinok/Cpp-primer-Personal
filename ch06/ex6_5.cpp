#include<iostream>

using namespace std;

int fact(int val)
{
	int i;
	if (val>=0)
	{
		i = val;
	}
	else
	{
		i = -val;
	}
	return i;
}

int main()
{
	cout << "请输入任意整数：";
	int j;
	cin >> j;
	int num = fact(j);
	cout << "这个数的绝对值是：" << num << endl;

	system("pause");
	return 0;
}
