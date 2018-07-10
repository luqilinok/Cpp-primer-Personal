#include<iostream>
#include<string>
#include<vector>

class Screen
{
public:
	//Window_mgj的成员可以访问Screen类的私有部分
	friend class Window_mgr;
	//Window_mgr::clear必须在Screen类之前被声明
	friend void Window_mgr::clear(ScreenIndex);
	using pos = std::string::size_type;  //使用类型别名等价地声明一个类型名字
	Screen() = default;  //1.默认构造函数
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' ') { }  //2.该构造函数接受宽和高的值，然后将contents初始化成给定数量的空白
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) { }  //3.该构造函数接受宽和高的值以及一个字符，该字符作为初始化之后屏幕的内容
	char get() const
	{
		return contents[cursor];
	}
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	//根据对象是否是const重载了display函数
	Screen &display(std::ostream &os)
	{
		do_display(os); return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os); return *this;
	}
	void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream &os) const
	{
		os << contents;
	}
	mutable size_t access_ctr;  //即使在一个const对象内也能被修改
};

inline
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;   //计算行的位置
	cursor = row + c;      //在行内将光标移动到指定的列
	return *this;          //以左值的形式返回对象
}
char Screen::get(pos r, pos c) const
{
	pos row = r * width;       //计算行的位置
	return contents[row + c];  //返回给定列的字符
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;  //设置当前光标所在位置的新值
	return *this;           //将this对象作为左值返回
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  //设置给定位置的新值
	return *this;                 //将this对象作为左值返回
}
void Screen::some_member() const
{
	++access_ctr;    //保存一个计数值，用于记录成员函数被调用的次数
	//该成员需要完成其他工作
}

class Window_mgr
{
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	//按照编号将指定的Screen重置为空白
	void clear(ScreenIndex);
	//向窗口添加一个Screen，返回它的编号
	ScreenIndex addScreen(const Screen&);

private:
	//这个Window_mgr追踪Screen
	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24,80,' ') };
};
//首先处理返回类型，之后我们才进入Window_mgr的作用域
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}
void Window_mgr::clear(ScreenIndex i)
{
	//s是一个Screen的引用，指向我们想清空的那个屏幕
	Screen &s = screens[i];
	// 将那个选定的Screen重置为空白
	s.contents = std::string(s.height*s.width, ' ');
}
