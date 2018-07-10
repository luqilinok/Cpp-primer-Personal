#include<iostream>
#include<string>

using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream &s = cerr) :os(s) {}
	template<typename T> void operator()(T *p) const { os << "deleting unique_ptr" << endl; delete p; }

private:
	ostream & os;
};
