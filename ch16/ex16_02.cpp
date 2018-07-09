#include<iostream>
#include<string>

using namespace std;

template<typename T> int comapare(const T &v1, const T &v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1)return 1;

	return 0;
}

int main()
{
	cout << comapare(1, 0) << endl;

	system("pause");
	return 0;
}
