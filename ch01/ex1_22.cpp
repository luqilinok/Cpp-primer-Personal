#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item total, trans;
	std::cout << "请输入几条ISBN相同的销售记录" << std::endl;
	if (std::cin >> total) {
		while (std::cin >> trans)
			if (compareIsbn(total, trans))  //ISBN相同
				total = total + trans;
			else                            //ISBN不同
			{
				std::cout << "ISBN不同" << std::endl;
				return -1;
			}
		std::cout << "汇总信息：ISBN、售出本数、销售额和平均售价为" << total << std::endl;
	}
	else
	{
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	system("pause");
	return 0;
}
