#include<iostream>
#include<vector>

using namespace std;

int f(int, int)  //6_54声明的函数
{
	return 0;
}
vector<decltype(f) *> v;    //6_54声明的vector对象

int func1(int a, int b)   //加法
{
	int num1;
	num1 = a + b;
	return num1;
}

int func2(int a, int b)  //减法
{
	int num2 = a - b;
	return num2;
}

int func3(int a, int b)  //乘法
{
	int num3 = a * b;
	return num3;
}

int func4(int a, int b)  //除法
{
	return a / b;
}

int main()
{
	decltype(func1) *p1 = func1;
	decltype(func2) *p2 = func2;
	decltype(func3) *p3 = func3;
	decltype(func4) *p4 = func4;
	vector<decltype(f) *> v = { p1,p2,p3,p4 };
	return 0;
}

