#include <string>
#include <iostream>

class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
	friend Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs);
public:
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) { }
	Sales_data(std::istream &is) { read(is, *this); }
	Sales_data(const Sales_data&);   //与合成的拷贝构造函数等价的拷贝构造函数的声明
	Sales_data& operator-=(const Sales_data &rhs);

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// member functions.
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
//与Sales_data的合成的拷贝构造函数等价
Sales_data::Sales_data(const Sales_data &orig) :
	bookNo(orig.bookNo),  //使用string的拷贝构造函数
	units_sold(orig.units_sold),  //拷贝orig.units_sold
	revenue(orig.revenue)  //拷贝orig.revenue
{  }  //空函数体

inline Sales_data & Sales_data::operator-=(const Sales_data & rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

// friend functions
std::istream &read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

inline Sales_data operator-(const Sales_data & lhs, const Sales_data & rhs)
{
	Sales_data sub = lhs;
	sub -= rhs;
	return sub;
}
