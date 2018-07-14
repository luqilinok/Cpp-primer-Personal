#include<iostream>
#include<cstddef>
#include<unordered_set>
#include<functional>
#include"ex16_62_Sales_data.h"

using namespace std;
using std::hash;

int main()
{
	unordered_multiset<Sales_data> SDset;
	Sales_data item;
	while (cin >> item)
	{
		SDset.insert(item);
	}
	cout << SDset.size() << endl;
	for (auto sd : SDset)
	{
		cout << sd << endl;
	}

	system("pause");
	return 0;
}
