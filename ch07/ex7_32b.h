#include<iostream>
#include<string>
#include<vector>

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);

private:
	std::vector<Screen> screens;
};

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;//等价于typedef std::string::size_type pos;

	Screen() = default;   //1.默认构造函数
	Screen(pos ht,pos wd):height(ht),width(wd),contents(ht*wd,' '){ }  //2.该构造函数接受宽和高的值，然后将contents初始化成给定数量的空白
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht*wd,c){ }  //3.该构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容

	char get() const { return contents[cursor]; }  //读取光标处的字符
	char get(pos r, pos c) const { return contents[r*width + c]; }
	inline Screen& move(pos r, pos c);
	inline Screen& set(char c);
	inline Screen& set(pos r, pos c, char ch);

	//根据对象是否是const重载了display函数
	const Screen& display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	Screen& do_display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}

private:
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
	
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r * width + c;
	return *this;
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[ r*width + c ] = ch;
	return *this;
}
