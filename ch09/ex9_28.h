#include<iostream>
#include<forward_list>
#include<string>

using namespace std;

void find_and_insert(forward_list<string> &list, string const &to_find, string const &to_add) //传引用调用（引用传递），通过使用引用传递，允许函数改变一个或多个实参的值，本题中需要插入string对象，因此需要使用传引用调用
{
	auto prev = list.before_begin();  //定义一个首前迭代器
	for (auto curr = list.begin(); curr != list.end(); curr++)
	{
		if (*curr==to_find)  //如果forward_list包含第一个string
		{
			list.insert_after(curr, to_add);  //将第二个string插入到list中第一个string之后
			return;
		}
	}
	list.insert_after(prev, to_add);  //如果list中没有第一个字符串，那么将第二个string插入到list中，即插入到首前迭代器之后
}
