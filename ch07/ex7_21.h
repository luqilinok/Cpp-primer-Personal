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
	Sales_data() = default;
	Sales_data(const std::string &s,unsigned n,double p):
		bookNo(s),units_sold(n),revenue(p*n){ }
	Sales_data(const std::string &s):bookNo(s){ }
	Sales_data(std::istream&);
	std::string isbn() const { return bookNo; }
	Sales_data &combine(const Sales_data&);

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
//Sales_data接口的非成员组成部分的声明(如果希望类的用户能够调用某个友元函数，必须在友元函数之外再专门对函数进行一次声明，如下所示)
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
