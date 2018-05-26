#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> iflst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = iflst.before_begin();  //声明一个首前迭代器
	auto curr = iflst.begin();

	while (curr != iflst.end())
	{
		if (*curr % 2 == 0)  //此时迭代器指向容器中的偶数
		{
			curr = iflst.erase_after(prev);  //删除prev之后的元素并将返回的prev之后的迭代器赋值给curr
		}
		else  //此时迭代器指向容器中的奇数
		{
			curr = iflst.insert_after(curr,*curr);
			prev = curr;  //移动迭代器curr，指向下一个元素，prev指向curr之前的元素
			curr++;
		}
	}

	//通过输出来进行验证
	for (curr = iflst.begin(); curr != iflst.end(); curr++)
	{
		cout << *curr << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
