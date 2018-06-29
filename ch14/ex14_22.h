#ifndef CP5_EX14_22_H
#define CP5_EX14_22_H

#include<iostream>
#include<string>

class Sales_data
{
	friend std::istream& operator>>(std::istream&, Sales_data&);
	friend std::ostream& operator<<(std::ostream&, const Sales_data&);
	friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data() :Sales_data("", 0, 0.0f) {}
	Sales_data(std::istream &is);

	Sales_data& operator=(const std::string&);

	Sales_data& operator+=(const Sales_data&);
	std::string isbn() const { return bookNo; }

private:
	inline double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}

Sales_data::Sales_data(std::istream &isalnum) :Sales_data()
{
	is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
	{
		item.revenue = price * item.units_sold;
	}
	else
	{
		item = Sales_data();
	}
	return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

Sales_data& Sales_data::operator=(const std::string &isbn)
{
	*this = Sales_data(isbn);
	return *this;
}

#endif // !CP5_EX14_22_H
