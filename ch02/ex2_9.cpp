#include<iostream>
int main()
{
	//(a)std::cin >> int input_value;//a是非法的，因为还没有定义变量，无法进行输入
	/*修改方式
	int input_value;
	std::cin >> input_value;*/

	/*int i = { 3.14 };  //b这种方法会被编译器警告，因为该语句定义了一个整形变量i，但是试图通过列表初始化的方式，把浮点数3.14赋值给i，这样做会造成小数部分的丢失，是一种不被建议的窄化操作*/

	/*double salary = wage = 9999.99;  //c这种方法是错误的，因为这种方法没有定义wage，如果希望将9999.99分别赋值给salary和wage，应该进行如下修改*/
	double salary, wage = 9999.99;

	int i = 3.14;//引发警告，因为int初始化的值通常都是整数，将3.14用int赋值，将导致小数部分的丢失，与（b）一样是窄化操作


}
