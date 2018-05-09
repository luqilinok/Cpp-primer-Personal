#include<iostream>
#include<string>



struct Sales_data
{
	std::string bookNo;      //书籍编号
	std::string bookName;    //书籍名称
	unsigned units_sold = 0; //销售量
	double revenue = 0.0;    //收入
	double price = 0.0;      //价格
	//...
};
