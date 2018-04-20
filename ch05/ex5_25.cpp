#include<iostream>
#include<stdexcept>

using namespace std;

int main()
{
	int a, b;
	cout << "请输入两个整数";
	while (cin>>a>>b)
	{
		try
		{
			if (b == 0)
				throw runtime_error("被除数不能为0");
			cout << a / b << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what();
			cout << "\n是否要重新输入？y or n: " << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
			{
				break;
			}
		}
	}
}
