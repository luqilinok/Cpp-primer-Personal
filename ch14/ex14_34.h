#include<iostream>
#include<string>

class IFElseThen
{
public:
	IFElseThen() {}
	IFElseThen(int i1, int i2, int i3) :iVal1(i1), iVal2(i2), iVal3(i3) {}

	int operator()(int i1, int i2, int i3)
	{
		return i1 ? i2 : i3;
	}

private:
	int iVal1, iVal2, iVal3;
};
