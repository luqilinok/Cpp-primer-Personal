#include<iostream>

using namespace std;

int main()
{
	int ia[3][4];
	int(*p)[4] = ia;
	p = &ia[2];
	using int_array = int[4];
	typedef int int_array[4];

	for (int_array *p = ia; p != ia + 3; ++p)
	{
		for (int *q = *p; q != *p + 4; ++q)
		{
			cout << *q << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
