#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}  //构造函数
	HasPtr(const HasPtr &p) :ps(new string(*p.ps)), i(p.i) { }  //拷贝构造函数
	HasPtr& operator=(const HasPtr&);  //拷贝赋值运算符
	HasPtr& operator=(const string&);  //赋予新string
	string &operator*();  //解引用
	bool operator<(const HasPtr&) const;  //比较运算
	~HasPtr();

private:
	string * ps;
	int i;
};

HasPtr::~HasPtr()
{
	delete ps;   //释放string内存
}

inline HasPtr& HasPtr::operator=(const HasPtr &rhs)  //拷贝赋值运算符
{
	auto newps = new string(*rhs.ps);
	delete ps;
	ps = newps;
	i = rhs.i;
	return *this;
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

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	cout << "交换" << *lhs.ps << "和" << *rhs.ps << endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
	return *ps < *rhs.ps;
}

