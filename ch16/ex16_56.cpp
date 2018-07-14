#include<iostream>
#include<string>
#include<map>
#include<cstddef>
#include"Sales_data.h"
#include"debug_rep.h"

using namespace std;

template<typename T>
ostream &print(ostream &os, const T &t)
{
	return os << t;
}

template<typename T, typename...Args>
ostream &print(ostream &os, const T &t, const Args&...rest)
{
	os << t << ",";
	return print(os, rest...);
}

template<typename...Args>
ostream &errorMsg(ostream &os, const Args...rest)
{
	return print(os, dubug_rep(rest)...);
}

struct ErrorCode
{
	ErrorCode(size_t n = 0) :e(n) {}
	size_t e;
	size_t num() const { return e; }
	string lookup() const { return errors[e]; }
	static map<size_t, string> errors;
};

map<size_t, string>
ErrorCode::errors = { {42,"some error"},{1024,"another error"} };

int main()
{
	Sales_data item("978-0590353403", 25, 15.99);
	string fcnName("itemProcess");
	ErrorCode code(42);
	string otherDate("invalid ISBN");

	errorMsg(cerr, fcnName, code.num(), otherDate, "other", item);
	cerr << endl;

	print(cerr, debug_rep(fcnName), debug_rep(code.num()), debug_rep(otherDate), debug_rep("otherData"), debug_rep(item));

	cerr << endl;

	system("pause");
	return 0;
}
