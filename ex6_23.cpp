#include<iostream>
using namespace std;

void print1(const int *p)   //使用标记指定数组长度
{
	if (p)
	{
		while (*p)
		{
			cout << *p++;
		}
	}
}

void print2(const int *beg, const int *end)  //传递指向数组首元素和尾后元素的指针
{
	while (beg!=end)
	{
		cout << *beg++ << endl;
	}
}

void print3(const int ia[], size_t size)   //显式定义一个表示数组大小的形参
{
	for (size_t i = 0; i !=size;++i)
	{
		cout << ia[i] << endl;
	}
}

void  print4(int(&arr)[2])  // 数组引用形参
{
	for (auto elem:arr)
	{
		cout << elem << endl;
	}
}

int main()
{
	int i = 0, j[2] = { 0,1 };
	//print1函数对于像int这样所有取值都是合法值的数据不太有效
	print2(begin(j), end(j));
	print3(j, end(j) - begin(j));
	print4(j);

	system("pause");
	return 0;
	
}
