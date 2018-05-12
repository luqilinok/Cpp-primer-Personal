#include<iostream>
#include<string>

class Screen
{
public:
	using pos = std::string::size_type; //等价于typedef std::string::size_type pos;
	Screen() = default;  //1.默认构造函数
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){ }//2.该构造函数接受宽和高的值，然后将contents初始化成给定数量的空白
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,'c'){ }//3.该构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

};
