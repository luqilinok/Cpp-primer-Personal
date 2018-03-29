#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	const int sz = 10;  //常量sz作为vector的容量
	vector<int> vInt, vInt2;
	//通过for循环为vector对象的元素赋值
	for (int i = 0; i < sz; ++i)
	{
		vInt.push_back(i);
	}
	for (int j = 0; j < sz; ++j)
	{
		vInt2.push_back(vInt[j]);
	}
	//通过for循环输出vector对象的全部元素
	for (auto val:vInt2)
	{
		cout << val << " ";
	}
	cout << endl;

	system("pause");
	return 0;
	
}
