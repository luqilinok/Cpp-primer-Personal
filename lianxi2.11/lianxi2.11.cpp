#include<iostream>
int main()
{
	extern int ix = 1024;//这是一个定义，但会引发错误
	int iy;   //这是一个声明并定义了变量iy
	extern int iz;  //这一个声明,声明了变量iz
}