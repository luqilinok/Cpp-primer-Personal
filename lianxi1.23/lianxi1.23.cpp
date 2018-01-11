#include<iostream>
#include"Sales_item.h"
int main()
{
	Sales_item trans1, trans2;
	int num = 1;
	std::cout << "请输入若干销售记录：" << std::endl;
	if (std::cin>>trans1)
	{
		while (std::cin>>trans2)
		{
			if (compareIsbn(trans1,trans2))         //ISBN相同
			{
				num++;
			}
			else                                   //ISBN不同
			{
				std::cout << trans1.isbn() << "共有" << num << "条销售记录" << std::endl;
				trans1 = trans2;
			}
		}
	}
	else
	{
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	system("pause");
	return 0;
}