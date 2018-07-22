#include<iostream>

using namespace std;

class Class
{
	//...
};

class Base :public Class
{
	//...
	Base() :ival(0) {}
	Base(int i) :ival(i) {}
	Base(const Base& b) :ival(b.ival) {}
protected:
	int ival;
};

class D1 :virtual public Base
{
	//...
public:
	D1() :Base(0) {};
	D1(int i) :Base(i) {}
	D1(const D1 &d) :Base(d) {}
};

class D2 :virtual public Base
{
	//...
public:
	D2() :Base(0) {};
	D2(int i) :Base(i) {};
	D2(const D2 &d) :Base(d) {}
};

class MI :public D1, public D2
{
	//...
public:
	MI() :Base(0) {}
	MI(int i) :Base(i), D1(i), D2(i) {}
	MI(const MI& m) :Base(m), D1(m), D2(m) {}
};

class Final :public MI, public Class
{
	Final() :Base(0) {}
	Final(int i) :Base(i), MI(i) {}
	Final(const Final& f) :Base(f), MI(f) {}
};
