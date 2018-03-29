#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()  //实现数组拷贝功能
{
	const int sz = 10;  // 常量sz作为数组的维度
	int a[sz], b[sz];
	//通过for循环为数组元素赋值
	for (int i = 0; i < sz; ++i)
	{
		a[i] = i;
	}
	for (int j = 0; j < sz; ++j)
	{
		b[j] = j;
	}
	//通过范围for循环输出数组的全部元素
	for (auto val:b )  //每次迭代，val会被初始化为b的下一个元素值
	{
		cout << val << " ";
	}

	system("pause");

	return 0;
}
