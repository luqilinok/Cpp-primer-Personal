#include<iostream>
using namespace std;

int compare(const int val, const int *p)
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
