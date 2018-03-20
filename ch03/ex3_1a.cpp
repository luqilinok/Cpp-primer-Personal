#include<iostream>
//使用using声明使得cout和endl在程序中可见
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	int i = 50;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	cout << "从50到100的数之和为" << sum << endl;

	system("pause");
	return 0;
}
