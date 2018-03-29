#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//array
	int array1[10];
	for (int i = 1; i < 10; ++i)
	{
		array1[i] = i;
	}
	int array2[10];
	for (int i = 0; i < 10; ++i)
	{
		array2[i] = array1[i];

	}

	
	
	system("pause");
	return 0;
}
