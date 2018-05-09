#include<iostream>
#include<string>
#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total;
	if (cin>>total.bookNo)
	{
		Sales_data trans;
		while (cin>>trans.bookNo)
		{
			if (total.bookNo==trans.bookNo)
			{
				total.units_sold += trans.units_sold;
				total.revenue += total.revenue;
			}
			else
			{
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
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
