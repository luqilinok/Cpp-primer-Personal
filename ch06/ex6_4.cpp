#include<iostream>

using namespace std;

int fact(int val)
{
	int ret = 1;
	while (val>1)
	{
		ret *= val--;
	}
	return ret;
}

int main()
{
	cout << "请输入一个整数：";
	int i;
	cin >> i;
	int factorial = fact(i);
	cout << "这个数的阶乘是：" << factorial << endl;

	system("pause");
	return 0;
}
