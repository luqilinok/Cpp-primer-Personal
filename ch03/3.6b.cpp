#include<iostream>

using namespace std;

int main()
{
	int ia[3][4];
	int(*p)[4] = ia;
	p = &ia[2];
	//p指向ia的第一个数组
	for (auto p=begin(ia);p!=end(ia);++p)
	{
		//q指向内层数组的首元素
		for (auto q = begin(*p); q != end(*p); ++q)
		{
			cout << *q << " ";
		}
	}

	cout << endl;

	system("pause");
	return 0;
}
