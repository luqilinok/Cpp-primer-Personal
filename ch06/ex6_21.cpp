#include<iostream>
using namespace std;

int compare(const int val, const int *p)   //因为在函数中指针只是进行比较操作，没有修改指针的值，所以指针的类型应该是const int*
{
	return(val > *p) ? val : *p;
}

int main()
{
	cout << "请输入两个个整数：" << endl;
	int a, b;
	cin >> a >> b;
	int *b_pointer = &b;
	cout << "较大的数为：" << compare(a, b_pointer) << endl;

	system("pause");
	return 0;
}
