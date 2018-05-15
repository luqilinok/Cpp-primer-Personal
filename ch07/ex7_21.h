#include<iostream>
#include<string>

class Sales_data
{
	//为Sales_data的非成员函数所做的友元声明
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::istream &read(std::istream &, Sales_data&);
	friend std::ostream &print(std::ostream&, Sales_data&);
	//其他成员及访问说明符与之前一致
public:
	//新增的构造函数
	Sales_data() = default;    //一个空参列表，定义了一个默认的构造函数
	Sales_data(const std::string &s) :bookNo(s) { }    //一个const string&，表示ISBN编号；编译器将赋予其他成员默认值
	Sales_data(const std::string &s, unsigned n, double p) :   //以下两行：一个const string&，表示ISBN编号，一个unsigned，表示售出的图书数量，一个double，表示图书的售出价格
		bookNo(s), units_sold(n), revenue(p*n) { }   //花括号之前的部分叫做构造函数初始值列表，作用是为新创建的对象的一个或几个成员函数赋值
	
	std::string isbn() const { return bookNo; }
		Sales_data &combine(const Sales_data&);
	Sales_data(std::istream&);
	

private:
	std::string bookNo; //书籍编号
	std::string bookName; //书籍名称
	unsigned units_sold = 0; //销售量
	double revenue = 0.0; //收入
	double price = 0.0;  //价格
};
//Sales_data接口的非成员组成部分的声明(如果希望类的用户能够调用某个友元函数，必须在友元函数之外再专门对函数进行一次声明，如下所示)
std::istream &read(std::istream &is, Sales_data&item);
std::ostream &print(std::ostream&os, const Sales_data&item);
Sales_data add(const Sales_data &lhs, const Sales_data&rhs);

