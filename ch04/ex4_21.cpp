#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using std::vector;

int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7,8,9 };
	for (auto i : ivec)
	{
		cout << ((i % 2 != 0) ? i * 2 : i) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
