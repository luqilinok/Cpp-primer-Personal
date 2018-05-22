#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec1 = { 1,2,3,4,5 };
	vector<int> ivec2 = { 1,2,3,4,5 };
	vector<int> ivec3 = { 1,2,3,4 };

	cout << (ivec1 == ivec2 ? "true" : "false") << endl;
	cout << (ivec1 == ivec3 ? "true" : "false") << endl;

	system("pause");
	return 0;
}
