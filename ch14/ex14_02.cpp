#include <string>
#include <iostream>

class Sales_data {
	friend std::istream& operator>>(std::istream&, Sales_data &);//输入
	friend std::ostream& operator<<(std::ostream&, const Sales_data &);//输出
	friend Sales_data operator+(const Sales_data &, const Sales_data &);

public:
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) { }
	Sales_data(std::istream &is);

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	double avg_price() const;
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

inline std::istream & operator>>(std::istream &is, Sales_data &item)
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

inline std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

inline Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum += rhs;
	return sum;
}

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}
