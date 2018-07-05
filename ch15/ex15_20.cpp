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

class Disc_quote :public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {}
	double net_price(std::size_t) const = 0;  //纯虚函数

protected:
	std::size_t quantity = 0;  //折扣适用的购买量
	double discount = 0.0;   //表示折扣的小数值
};

class Limited_quote :public Disc_quote
{
public:
	Limited_quote() = default;
	Limited_quote(const std::string &book, double price, std::size_t qty, double disc) :Disc_quote(book, price, qty, disc) {}
	double net_price(std::size_t) const override;
};

class Limited_quote :public Disc_quote
{
public:
	Limited_quote(const std::string &book, double p, std::size_t qty, double disc) :Disc_quote(book, p, qty, disc), max_qty(qty), discount(disc) {}
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

class Base
{
public:
	void pub_mem();
protected:
	int prot_mem();

private:
	char priv_mem;
};

struct Pub_Derv :public Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Priv_Derv :private Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Prot_Derv :protected Base
{
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public :public Pub_Derv
{
	void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv
{
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
	//void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected : public Prot_Derv
{
	void memfcn(Base &b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
	Base *p = &d1;

	Priv_Derv d2;
	//p = &d2;

	Prot_Derv d3;
	//p = &d3;

	Derived_from_Public dd1;
	p = &dd1;

	Derived_from_Private dd2;
	//p =& dd2;

	Derived_from_Protected dd3;
	//p = &dd3;

	system("pause");
	return 0;
}
