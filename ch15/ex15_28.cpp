#include<iostream>
#include<vector>
#include<algorithm>
#include"Quote.h"

using namespace std;

int main(int argc, char *argv[])
{
	vector<Quote> vec1;
	Bulk_quote b1(string("C++ Primer 1"), 128, 10, 0.5);
	Bulk_quote b2(string("C++ Primer 2"), 118, 8, 0.6);
	Bulk_quote b3(string("C++ Primer 3"), 108, 12, 0.4);
	Bulk_quote b4(string("C++ Primer 4"), 138, 4, 0.3);
	vec1.push_back(b1);
	vec1.push_back(b2);
	vec1.push_back(b3);
	vec1.push_back(b4);
	double Sum_of_net_price1 = 0;
	for (int i = 0; i < vec1.size(); ++i)
	{
		Sum_of_net_price1 += vec1[i].net_price(20);
		cout << Sum_of_net_price1 << endl;
	}
	cout << "The total net price is" << Sum_of_net_price1 << endl;



	system("pause");
	return 0;
}
