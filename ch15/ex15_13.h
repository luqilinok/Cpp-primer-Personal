#include<iostream>
#include<string>

using namespace std;

class base
{
public:
	string name() { return basename; }
	virtual void print(ostream &os){os<<basename}
private:
	string basename;
};

class derived:public base
{
public:
	void base::print(ostream &os) { print(os) << " " << i; }

private:
	int i;
};
