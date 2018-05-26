#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> ival;
	list<int> ilist;

	ival.assign(ia, ia + 11);
	ilist.assign(ia, ia + 11);

	vector<int>::iterator iival = ival.begin();
	list<int>::iterator iilist = ilist.begin();
	
	//删除list中的奇数
	while (iilist!=ilist.end())
	{
		if (*iilist%2==0)  //证明此时指向的是ilist中的偶数
		{
			++iilist;
		}
		else  //此时指向的是奇数
		{
			iilist = ilist.erase(iilist);   //删除此元素
		}
	}

	//删除vector中的偶数
	while (iival!=ival.end())
	{
		if (*iival%2==0)  //此时指向的是偶数
		{
			iival = ival.erase(iival);  //删除这个偶数
		}
		else   //否则此时指向的是一个奇数
		{
			++iival;
		}
	}

	//通过输出来验证
	for ( iilist=ilist.begin();iilist!=ilist.end();iilist++)
	{
		cout << *iilist<<" ";
	}
	cout << endl;

	for (iival = ival.begin(); iival != ival.end(); iival++)
	{
		cout << *iival << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
