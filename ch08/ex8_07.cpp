#include<iostream>
#include<fstream>
#include<string>
#include"Sales_data(struct).h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream input(argv[1]);   //打开销售记录文件
	ofstream output(argv[2]);  //打开输出文件
	Sales_data total;         //保存销售总量的变量
	if (read(input, total))  //读取第一条销售记录
	{
		Sales_data trans;    //保存下一条销售记录的变量
		while (read(input, trans))       //读取剩余记录
		{
			if (total.isbn() == trans.isbn())   //检查isbn
			{
				total.combine(trans);    //更新销售总额
			}
			else
			{
				print(output, total) << endl;     //打印结果
				total = trans;    //处理下一本书
			}
		}
		print(output, total) << endl;    //打印最后一本书的销售额
	}
	else
	{
		cerr << "No data?!" << endl;   //文件中无输入数据
	}
	system("pause");
	return 0;
}
