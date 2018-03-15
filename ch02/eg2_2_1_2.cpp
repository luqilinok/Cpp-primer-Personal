#include<iostream>
#include"Sales_item.h"
int main()
{
	double price = 109399, discount = price * 0.16;  //正确:price先被定义并赋值，随后被用于初始化discount
	double salePrice = applyDiscount(price, discount);
}
