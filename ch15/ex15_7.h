#include<iostream>
#include<string>

using namespace std;

class Bulk_quote :public Quote
{
public:
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :Quote(book, p), max_qty(qty), discount(disc) {}
	double net_price(size_t cnt) const override
	{
		if (cnt <= max_qty)
		{
			return cnt * (1 - discount)*price;
		}
		else
		{
			return cnt * price;
		}
	}
private:
	size_t max_qty;
	double discount;
};
