#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class IntCompare
{
public:
	IntCompare(int v) :val(v) {}
	bool operator()(int v) { return val == v; }

private:
	int val;
};

int main()
{
	vector<string> vec = { 1,2,3,2,1 };
	const int oldValue = 2;
	const int newValue = 200;
	IntCompare icmp(oldValue);
	std::replace_if(vec.begin(), vec.end(), icmp, newValue);  //replace()将区间[beg,end)之内每一个“与oldValue相等”的元素替换为newValue

	return 0;
}
