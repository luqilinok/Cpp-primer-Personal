#include<iostream>
#include<vector>
#include<algorithm>
#include"demo.h"

using namespace std;

int main(int argc, char *argv[])
{


	vector<shared_ptr<Quote>> vec2;

	vec2.push_back(make_shared<Bulk_quote>(b1));
	vec2.push_back(make_shared<Bulk_quote>(b2));
	vec2.push_back(make_shared<Bulk_quote>(b3));
	vec2.push_back(make_shared<Bulk_quote>(b4));
	double Sum_of_net_price2 = 0;
	for (int i = 0; i < vec2.size(); ++i)
	{
		Sum_of_net_price2 += vec2[i]->net_price(20);
		cout << Sum_of_net_price2 << endl;
	}
	cout << "The total net price is" << Sum_of_net_price2 << endl;

	system("pause");
	return 0;
}
