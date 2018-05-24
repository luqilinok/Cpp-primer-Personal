/*创建一个容器为另一个容器的拷贝，最好的方法是使用迭代器*/

#include<iostream>
#include<list>
#include<deque>

using namespace std;

int main()
{
	list<int> ilist = { 1,2,3,4,5,6,7,8 };
	deque<int> odd_d;  //奇数
	deque<int> even_d; //偶数

	for (auto iter=ilist.begin();iter!=ilist.end();iter++)
	{
		if ((*iter)%2==0)   //如果迭代器所指的是偶数
		{
			even_d.push_back(*iter);
		}
		else   //否则迭代器所指的是奇数
		{
			odd_d.push_back(*iter);
		}
	}
	cout << "偶数值有：";
	for (auto iter = even_d.begin(); iter != even_d.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	cout << "奇数值有：";
	for (auto iter=odd_d.begin();iter!=odd_d.end();iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	system("pause");
	return 0;
}
