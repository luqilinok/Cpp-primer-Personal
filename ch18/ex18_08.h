#include<iostream>
#include<stdexcept>

using namespace std;

class MyTest_Base
{
public:
	virtual ~MyTest_Base()
	{
		cout << "开始准备销毁一个MyTest_Base类型的对象" << endl;
		//把异常完全封装在析构函数内部
		try
		{
			//注意：在析构函数中抛出了异常
			throw std::exception("在析构函数中故意抛出一个异常，测试！");
		}
		catch (...) {}
	}

	void Func()throw()
	{
		throw std::exception("故意抛出一个异常，测试！")；
	}
	void Other() {}
};
