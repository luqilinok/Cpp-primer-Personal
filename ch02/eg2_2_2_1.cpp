#include<iostream>
int main()
{
	extern int i;  //声明i而非定义i
	int j;         //声明并定义j
	extern double pi = 3.1416;  //定义，这是一个错误的写法
}
