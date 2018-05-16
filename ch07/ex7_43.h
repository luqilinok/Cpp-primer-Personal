#include<vector>

class Nodefault
{
public:
	Nodefault(int i){ }
};

class C
{
public:
	C():def(0){ }  //定义了C的构造函数

private:
	Nodefault def;
};
