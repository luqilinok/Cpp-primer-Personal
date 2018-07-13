#include<iostream>

using namespace std;

template<typename T, typename ...Args>
void foo(T t, Args...args)
{
	cout << sizeof...(Args) << endl;
	cout << sizeof...(args) << endl;
}

int main()
{
	foo(1, 2);
	foo(1, 23, 4, 5, 6);
}
