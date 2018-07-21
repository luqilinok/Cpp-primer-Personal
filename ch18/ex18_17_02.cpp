#include<iostream>

namespace Exercise
{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}

int ivar = 0;

//位置1

int main()
{
	//位置2
	using Exercise::ivar;
	using Exercise::dvar;
	using Exercise::limit;

	double dvar = 3.1416;  //编译错误：重复定义
	int iobj = limit + 1;  //Exercise::limit
	++ivar;   //Exercise::ivar
	++::ivar;  //全局ivar
	return 0;
}
