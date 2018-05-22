/*比较两个容器是否相等的步骤：
   首先判断两个容器是否包含相同个数的元素，若不等，则两个容器也不等
   否则，遍历两个容器中的元素，两两比较对位元素的值，若有元素不相等，则容器不等，否则，两个容器相等*/


#include<iostream>
#include<vector>
#include<list>

using namespace std;
using std::vector;
using std::list;

bool l_v_equal(vector<int>&ivec, list<int>&ilist)  //比较list和vector元素个数
{
	if (ilist.size()!=ivec.size())
	{
		return false;
	}
	auto lb = ilist.cbegin();
	auto le = ilist.cend();
	auto vb = ivec.cbegin();
	for (; lb !=le;lb++,vb++)
	{
		if (*lb!=*vb)   //元素不等，容器不等
		{
			return false;
		}
		
	}
	return true;   //容器相等
}

int main()
{
	vector<int> ivec = { 1,2,3,4,5,6,7 };
	list<int> ilist = { 1,2,3,4,5,6,7 };
	list<int> ilist1 = { 1,2,3,4,5,};
	list<int>ilist2 = { 1,2,3,4,5,6,8 };
	list<int>ilist3 = { 1,2,3,4,5,7,6 };

	cout << l_v_equal(ivec, ilist) << endl;
	cout << l_v_equal(ivec, ilist1) << endl;
	cout << l_v_equal(ivec, ilist2) << endl;
	cout << l_v_equal(ivec, ilist3) << endl;

	system("pause");
	return 0;
}
