#ifndef EX13_30_H
#define EX13_30_H

#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {} //构造函数
	HasPtr(const HasPtr &hp) :ps(new string(*hp.ps)), i(hp.i) {} //拷贝构造函数
	HasPtr& operator=(const HasPtr &hp)  //拷贝赋值运算符
	{
		auto newps = new string(*hp.ps);
		delete ps;
		ps = newps;
		i = hp.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}
	void show() { std::cout << *ps << std::endl; }
private:
	string * ps;
	int i;
};

inline void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap(HasPtr& lhs,HasPtr &rhs)" << std::endl;
}
#endif // !EX13_30_H
