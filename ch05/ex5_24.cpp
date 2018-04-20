#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int a, b;
	cout << "请输入两个整数";
	while (cin>>a>>b)
	{
			if (b == 0)
				throw runtime_error("被除数不能为0");
			cout << a / b << endl;
	
		
	}
}
//系统会因为只要throw语句而没有catch语句的原因，当除数出现0的情况下不会报错，而是直接会终止异常。
