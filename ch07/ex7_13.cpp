#include<iostream>
#include"Sales_data.h"

using namespace std;

int main()
{
	Sales_data total(cin);
	if (cin)
	{
		Sales_data trans(cin);
		do
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
		} while (read(cin,trans));
		print(cout, total) << endl;
	}
	else
	{
		cerr << "No data?!" << endl;
	}

	system("pause");
	return 0;
}
