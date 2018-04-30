#include<iostream>
using namespace std;

void ChangePointer1(int *p, int *q)  //该函数既不交换指针，也不交换指针所指的内容
{
	int *temp = p;
	p = q;
	q = temp;
}
void ChangePointer2(int *p, int *q)  //该函数交换指针所指的内容
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
void ChangePointer3(int * &p, int * &q)  //该函数交换指针所指的内存地址
{
	int *temp = p;
	p = q;
	q = temp;
}

int main()
{
	int a = 5, b = 10;
	int *p = &a, *q = &b;
	cout << "交换前：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;
	ChangePointer1(p, q);
	cout << "交换后：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;

	a = 5, b = 10;
	p = &a, q = &b;
	cout << "交换前：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;
	ChangePointer2(p, q);
	cout << "交换后：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;

	a = 5, b = 10;
	p = &a, q = &b;
	cout << "交换前：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;
	ChangePointer3(p, q);
	cout << "交换后：" << endl;
	cout << "p的值是：" << p << ",q的值是： " << q << endl;
	cout << "p所指的值是：" << *p << ",q所指的值是：" << *q << endl;

	system("pause");
	return 0;
}
