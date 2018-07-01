#include<iostream>
#include<vector>

class StrBlobPtr
{
public:
	//前置运算符
	StrBlobPtr & operator++();
	StrBlobPtr & operator--();

	//后置运算符
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

private:
	//和之前一样
};

StrBlobPtr& StrBlobPtr::operator++()   //前置版本，返回递增/递减对象的引用
{
	//如果curr已经指向了容器的尾后位置，则无法递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;//将curr在当前状态下向前移动一个元素
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	//如果curr是0，则继续递减它将产生一个无效下标
	--curr;   //将curr在当前状态下向后移动一个元素
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	//此处无需检查有效性，调用前置递增运算时才需要检查
	StrBlobPtr ret = *this;  //记录当前的值
	++(*this);  //向前移动一个元素，前置++需要检查递增的有效性
	return ret;  //返回之前记录的状态
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	//此处无需检查有效性，调用前置递增运算时才需要检查
	StrBlobPtr ret = *this;  //记录当前的值
	--(*this);  //向后移动一个元素，前置--需要检查递减的有效性
	return ret;   //返回之前记录的状态
}
