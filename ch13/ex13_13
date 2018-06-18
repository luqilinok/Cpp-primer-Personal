#include<iostream>
#include<vector>
#include<initializer_list>

struct X
{
	X() { std::cout << "构造函数X()" << std::endl; }
	X(const X&) { std::cout << "拷贝构造函数X(const X&)" << std::endl; }
	X& operator=(const X &rhs) { std::cout << "拷贝赋值运算符=(const X&)" << std::endl; return *this; }
	~X()
	{
		std::cout << "析构函数~X()" << std::endl;
	}
};

void f1(X x)
{
}

void f2(X &x)
{
}

int main(int argc, char *argv[])
{
	std::cout << "局部变量：" << std::endl;
	X x;
	std::cout << std::endl;

	std::cout << "非引用参数传递：" << std::endl;
	f1(x);
	std::cout << std::endl;

	std::cout << "引用参数传递：" << std::endl;
	f2(x);
	std::cout << std::endl;

	std::cout << "动态分配：" << std::endl;
	X *px = new X;
	std::cout << std::endl;

	std::cout << "添加到容器中：" << std::endl;
	std::vector<X> vx;
	vx.push_back(x);
	std::cout << std::endl;

	std::cout << "释放动态分配对象：" << std::endl;
	delete px;
	std::cout << std::endl;

	std::cout << "间接初始化和赋值：" << std::endl;
	X y = x;
	y = x;
	std::cout << std::endl;

	std::cout << "程序结束" << std::endl;

	system("pause");
	return 0;
}
