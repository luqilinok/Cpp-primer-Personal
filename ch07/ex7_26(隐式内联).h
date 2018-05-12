#include<iostream>
#include<string>

class Sales_data
{
public:
	double avg_price() const
	{
		if (units_sold)
		{
			return revenue / units_sold;
		}
		else
		{
			return 0;
		}
	}

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
