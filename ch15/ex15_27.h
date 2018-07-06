#include<iostream>
#include<string>

using namespace std;

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }   //返回给定数量的书籍的销售总额，派生类改写并使用不同的折扣计算方法
	virtual double net_price(std::size_t n)const { return n * price; }
	virtual ~Quote() = default;   //对析构函数进行动态绑定
private:
	std::string bookNo;  //书籍的ISBN编号
protected:
	double price = 0.0;  //代表普通状态下不打折的价格
};

double print_total(ostream &os, const Quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者BUlk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn() << "# sold:" << n << "total due: " << ret << endl;

	return ret;
}

class Disc_quote :public Quote
{
public:
	Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) :Quote(book, sales_price), quantity(qty), discount(disc) {}
	double net_price(size_t cnt) const = 0;  //纯虚函数
protected:
	size_t quantity;
	double discount;
};

class Bulk_quote :public Disc_quote
{
public:
	using Disc_quote::Disc_quote;   //继承构造函数
	double net_price(size_t cnt) const
	{
		if (cnt > quantity)
		{
			return cnt * (1 - discount)*price;
		}
		else
		{
			return cnt * price;
		}
	}
};
