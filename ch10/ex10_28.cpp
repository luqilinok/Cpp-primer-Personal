#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	vector<int> vi = { 1,2,3,4,5,6,7,8,9 };
	vector<int> vi1, vi2, vi3;

	//iterator
	copy(vi.begin(), vi.end(), inserter(vi1, vi1.begin()));
	for (auto a:vi1)
	{
		cout << a << " ";
	}
	cout << endl;

	//back_iterator
	copy(vi.begin(), vi.end(), back_inserter(vi2));
	for (auto b:vi2)
	{
		cout << b << " ";
	}
	cout << endl;
	//front_iterator
	copy(vi.begin(), vi.end(), front_inserter(vi3));
	for (auto c:vi3)
	{
		cout << c << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
