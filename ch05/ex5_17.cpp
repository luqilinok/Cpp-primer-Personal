#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>  v1 = { 0,1,1,2 };
	vector<int> v2 = { 0,1,1,2,3,5,8 };

	auto it1 = v1.cbegin();
	auto it2 = v2.cbegin();

	while (it1!=v1.cend()&&it2!=v2.cend())
	{
		if (*it1!=*it2)  //如果当前位置的两个元素不相等，那么一定这两个对象一定没有前缀关系，退出循环
		{
			cout << "v1和v2没有前缀关系" << endl;
			break;
		}
		++it1;
		++it2;
	}
	if (it1==v1.cend())
	{
		cout << "v1是v2的前缀" << endl;
	}
	if (it2==v2.cend())
	{
		cout << "v2是v1的前缀" << endl;
	}

	system("pause");
	return 0;
}
