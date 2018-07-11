#include<iostream>
#include<vector>
#include<string>

using namespace std;

template<typename T>
auto sum(T lhs, T rhs)->decltype(lhs + rhs)
{
	return lhs + rhs;
}

int main()
{
	auto s = sum(12, 25);

	cout << "the sum is: " << s << endl;

	system("pause");
	return 0;
}
