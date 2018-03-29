#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int array[10];
	for (auto i=0;i<10;++i)
	{
		array[i] = i;
	}
	for (auto i : array)
	{
		cout << i << " ";
	}

	system("pause");
	return 0;

}
