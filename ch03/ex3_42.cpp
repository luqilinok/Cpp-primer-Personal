#include<iostream>
#include<vector>

using namespace std;
using std::vector;
using std::begin;
using std::end;

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	int arr[10];
	for (auto i : arr)
	{
		cout << i << " ";
	}

	system("pause");
	return 0;
}
