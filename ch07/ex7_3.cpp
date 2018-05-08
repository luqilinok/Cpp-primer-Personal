#include<iostream>
#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;  //保存当前求和结果的变量
	if (cin>>total.bookNo>>total.units_sold>>total.revenue)
	{
		Sales_data trans;  
		while (cin>>total.bookNo>>total.units_sold>>total.revenue)
		{
			if (total.isbn()==trans.isbn())
			{
				total.combine(trans);
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
