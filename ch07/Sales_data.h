#include<iostream>
#include<string>

using namespace std;

struct Sales_data
{
	//新增的构造函数
	Sales_data() = default;  //一个空参列表，定义了一个默认的构造函数
	Sales_data(const std::string &s) :bookNo(s) { }  //一个const string&，表示ISBN编号；编译器将赋予其他成员默认值
	Sales_data(const std::string &s,unsigned n,double p):  //以下两行：一个const string&，表示ISBN编号，一个unsigned，表示售出的图书数量，一个double，表示图书的售出价格
		bookNo(s),units_sold(n),revenue(p*n) { } //花括号之前的部分叫做构造函数初始值列表，作用是为新创建的对象的一个或几个成员函数赋值
	
	Sales_data(std::istream &is);   //一个istream&，从中读取一条交易信息


	std::string isbn() const { return bookNo; };
		Sales_data& combine(const Sales_data&);
	double avg_price() const;

	std::string bookNo; //书籍编号
	std::string bookName; //书籍名称
	unsigned units_sold = 0; //销售量
	double revenue = 0.0; //收入
	double price = 0.0;  //价格
};


double Sales_data::avg_price() const
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



inline Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);  //read函数的作用是从is中读取一条交易信息，然后存入this对象中
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream &read(istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}
