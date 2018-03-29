#include<iostream>
#include<vector>
#include<iterator>

using std::begin;
using std::end;
using std::vector;
using std::cout;
using std::endl;

bool compare(int* const pb1, int* const pe1, int* pb2, int* pe2)
{
	if ((pe1-pb1)!=(pe2-pb2))
	{
		return false;
	}
	else
	{
		for (int* i = pb1,*j=pb2;(i!=pe1)&&(j!=pe2);++i,++j)
		{
			if (*i!=*j)
			{
				return false;
			}
		}
	}
	return false;
}

int main()
{
	int arr1[3] = { 0,1,2 };
	int arr2[3] = { 0,2,4 };
	if (compare(begin(arr1),end(arr1),begin(arr2),end(arr2)))
	{
		cout << "The two arrays are equal." << endl;
	}
	else
	{
		cout << "The two arrays are not equal." << endl;
	}

	cout << "=========" << endl;

	vector<int> vec1 = { 0,1,2 };
	vector<int> vec2 = { 0,1,2 };
	if (vec1 ==vec2)
	{
		cout << "The two vectors are equal." << endl;
	}
	else
	{
		cout << "The two vectors are not equal." << endl;
	}

	system("pause");
	return 0;
}
