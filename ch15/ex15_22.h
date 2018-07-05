#ifndef FLOWER_H
#define FLOWER_H

#include<iostream>
#include<string>

using namespace std;

class Flower
{
public:
	Flower(); //默认构造函数
	Flower(const string &s, double sale_price) :name(s), Price(sale_price) {}  //构造函数
	virtual int net_price() const = 0; //纯虚函数，本身无意义
protected:
	double Price;  //价格

private:
	string name;
};

class Rose :public Flower  //普通玫瑰
{
public:
	Rose();
	Rose(const string &SR, double n, size_t m) :Flower(SR, n), quantity(m) {}
	int net_price() const
	{
		return quantity * Price;
	}
protected:
	size_t quantity;  //销售量
};

class Discount_Rose :public Rose
{
public:
	Discount_Rose();
	Discount_Rose(const string &SR, double n, size_t m, double disc) :Rose(SR, n, m), discount(disc) {}
	int net_price() const
	{
		return quantity * Price*(1 - discount);
	}

protected:
	double discount;  //折扣
};

#endif // !FLOWER_H
