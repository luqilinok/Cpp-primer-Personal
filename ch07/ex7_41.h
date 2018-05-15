#include <iostream>
#include <string>

class Sales_data {
	friend std::istream &read(std::istream &is, Sales_data &item);
	friend std::ostream &print(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:  
	//非委托构造函数使用对应的实参初始化成员
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p)
	{
		std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
	}
	//其余构造函数全部委托给另一个构造函数
	Sales_data() : Sales_data("", 0, 0.0f)
	{
		std::cout << "Sales_data()" << std::endl;
	}

	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}

	Sales_data(std::istream &is);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

private:
	inline double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// 友元函数
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
