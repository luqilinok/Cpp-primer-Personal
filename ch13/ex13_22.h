#ifndef EX13_22_H
#define EX13_22_H

#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) { }
	HasPtr(const HasPtr &p) :ps(new string(*p.ps)), i(p.i) { }  //拷贝构造函数
	HasPtr& operator=(const HasPtr&);  //拷贝赋值运算符
	HasPtr& operator=(const string&);  //赋予新string
	string& operator*();
	~HasPtr();

private:
	string * ps;
	int i;
};

HasPtr::~HasPtr()
{
	delete ps;
}

inline
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	auto newps = new string(*rhs.ps); //拷贝指针指向的对象
	delete ps;  //销毁原来的string
	ps = newps;   //指向新string
	i = rhs.i;   //使用内置的int赋值
	return *this;  //返回一个此对象的引用
}

HasPtr& HasPtr::operator=(const string &rhs)
{
	*ps = rhs;
	return *this;
}

string& HasPtr::operator*()
{
	return *ps;
}
#endif // !EX13_22_H
