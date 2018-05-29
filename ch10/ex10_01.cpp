#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using std::vector;

int main()   //统计vector容器中1出现的次数
{
	vector<int> val{ 1,1,10,20 };
	auto times = count(val.cbegin(), val.cend(), 1);
	cout << "the times of 1 is " << times << endl;

	system("pause");
	return 0;
}
