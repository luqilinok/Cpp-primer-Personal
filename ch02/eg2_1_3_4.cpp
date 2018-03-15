#include<iostream>
using namespace std;
int main()
{
	long double ld = 3.1415926536;
	int a(ld), b = { ld };  //错误：转换未执行，因为存在丢失信息的危险
	int c(ld), d = ld;  //正确：转换智行，且确实丢失了部分值
}
