#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
	HasPtr(const string &s = string()) :ps(new string(s), i(0){ }
		HasPtr(const HasPtr &p) :ps(new string(*p.ps)), i(p.i) { }
	HasPtr& operator=(const HasPtr&);
	HasPtr& operator=(const string&);
	string& operator*();
	~HasPtr();

private:
	string * ps;
	int i;
};

HasPtr::HasPtr()
{
}

HasPtr::~HasPtr()
{
}
