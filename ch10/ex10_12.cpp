#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include"Sales_data(class).h"

using namespace std;

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn().size() < rhs.isbn().size();
}
int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout <<"打开输入文件失败！"<< endl;
		return -1;
	}

	vector<Sales_data> sds;
	Sales_data sd;
	while (read(in,sd))
	{
		sds.push_back(sd);
	}

	sort(sds.begin(), sds.end(), compareIsbn);

	for (const auto &s:sds)
	{
		print(cout, s);
		cout << endl;
	}

	system("pause");
	return 0;
}
