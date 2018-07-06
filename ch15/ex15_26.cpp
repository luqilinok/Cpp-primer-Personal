#include <string>
#include <iostream>
using namespace std;
class Quote
{
	friend double print_total(ostream &,const Quote&,size_t);//定义为友元函数
public:
	/*	Quote() = default;//C++11新特性*/
	Quote();//默认构造函数
	Quote(const string &book,double sales_price):BookNo(book),price(sales_price){};//构造函数
	Quote (const Quote& quote1):BookNo(quote1.BookNo),price(quote1.price)//拷贝构造函数
	{
		cout<<"拷贝构造函数"<<endl;
	}
	Quote& operator=(const Quote& quote2)//拷贝赋值运算符
	{
		if (*this != quote2)//防止自赋值的情况
		{
			BookNo = quote2.BookNo;
			price = quote2.price;
		}	
		cout<<"拷贝赋值运算符"<<endl;
		return *this;
	}
	Quote (const Quote&& quote3):BookNo(move(quote3.BookNo)),price(move(quote3.price))//移动构造函数
	{
		cout<<"移动构造函数"<<endl;
	}
	Quote& operator=(const Quote&& quote4) noexcept//移动赋值运算符
	{
		if (*this != quote4)
		{
			BookNo = move(quote4.BookNo);
			price = move(quote4.price);
		}
		cout<<"拷贝赋值运算符"<<endl;
		return *this;
	}
	string isbn() const{return BookNo;};//保存每本书籍的编号
	virtual double net_price(size_t n) const//定义为虚函数，让派生类自己定价
	{
		return n*price;
	}
	virtual void debug()
	{
		cout<<"This is Quote Class"<<endl;
		cout<<"ISBN: "<<BookNo<<endl;
		cout<<"Price: "<<price<<endl;
	}
 
private:
	string BookNo;//书籍的ISBN编号
protected:
	double price;//普通状态下不打折的价格，C++11不支持非静态变量的类内初始化
 
};
