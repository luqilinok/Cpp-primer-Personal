#include<iostream>
#include<string>

class Screen
{
public:
	typedef std::string::size_type pos;//等价于using pos = std::string::size_type;
	Screen() = default;//因为Screen有另一个构造函数，所以本函数是必须的

	//cursor被其类内初始值初始化为0
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){ }
	char get() const  // 读取光标处的字符
	{
		return contents[cursor];  //隐式内联函数
	}
	inline char get(pos ht, pos wd) const;  //显示内联
	Screen &move(pos r, pos c);   //能在之后被设置成内联函数
	

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline                                //可以在函数的定义处指定inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;   //计算行的位置
	cursor = row + c;      //在行内将光标移动到指定的列
	return *this;         //以左值的形式返回对象
}

char Screen::get(pos r, pos c) const          //在类的内部声明成inline
{
	pos row = r * width;   //计算行的位置
	return contents[row + c];  //返回给定列的字符
}

