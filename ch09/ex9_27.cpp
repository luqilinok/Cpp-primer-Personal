#include<iostream>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	forward_list<int>::iterator prev = flst.before_begin();
	forward_list<int>::iterator curr = flst.begin();
	while (curr!=flst.end())
	{
		if (*curr%2==0)   //容器中元素是偶数
		{
			prev = curr;  //移动迭代器curr，指向下一个元素，prev指向curr之前的元素
			++curr;
		}
		else    //容器中的元素是奇数
		{
			curr = flst.erase_after(prev);  //删除prev之后的元素并将返回的prev之后的迭代器赋值给curr
		}
	}

	//通过输出来验证
	for ( curr = flst.begin(); curr != flst.end(); curr++)
	{
		cout << *curr << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
