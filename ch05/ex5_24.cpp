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
