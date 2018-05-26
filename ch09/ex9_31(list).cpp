#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> list = { 0,1,2,3,4,5,6,7,8,9 };
	auto curr = list.begin();

	while (curr!=list.end())
	{
		if (*curr%2==0)  //curr此时指向容器中的偶数
		{
			curr = list.erase(curr);
		}
		else   //curr此时指向容器中的奇数
		{
			curr = list.insert(curr, *curr);
			curr++; curr++;
		}
	}

	//通过输出来进行验证
	for (curr = list.begin(); curr != list.end(); curr++)
	{
		cout << *curr << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
