#include<iostream>
#include"ex15_5.h"

using namespace std;

int main()
{
	Quote q("textbook", 10.60);
	Bulk_quote bq("textbook", 10.60, 10, 0.3);

	print_total(std::cout, q, 12);
	print_total(std::cout, bq, 12);

	system("pause");
	return 0;
}
