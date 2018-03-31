#include<iostream>

using namespace std;

int main()
{
	int ia[3][4];
	int(*p)[4] = ia;
	p = &ia[2];
	//输出ia中每个元素的值，每个内层数组各占一行
	//p指向含有4个整数的数组
	for (auto p=ia;p!=ia+3;++p)
	{
		//q指向4个整数数组的首元素
		for (auto q=*p;q != *p+4 ; ++q)
		{
			cout << *q << ' ';
		}
		cout << endl;
	}
	

	system("pause");
	return 0;
}
