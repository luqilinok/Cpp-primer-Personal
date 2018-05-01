#include<iostream>
#include<vector>

using namespace std;
using std::vector;

void print(vector<int> vInt, int index)
{
	unsigned sz = vInt.size();
	if (!vInt.empty() && index < sz)
	{
		cout << vInt[index] << endl;
		print(vInt, index + 1);   //递归调用
	}
}

int main()
{
	vector<int> v= {0, 1, 2, 3, 4, 5, 6, 7};
	print(v, 0);

	system("pause");
	return 0;
}
