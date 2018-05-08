  #include<iostream>
#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;  //保存当前求和结果的变量
	if (read(cin,total))  //读入第一笔交易
	{
		Sales_data trans;  //保存下一条交易数据的变量
		while (read(cin,trans))
		{
			if (total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
		cerr << " No data?!" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
