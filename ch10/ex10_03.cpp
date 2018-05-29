#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

int main()
{
	vector<int> v = { 1,2,3,4 };
	auto sum = accumulate(v.cbegin(), v.cend(), 0);
	
	cout << "the sum is " << sum << endl;
	system("pause");
	return 0;
}
