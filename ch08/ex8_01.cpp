#include<iostream>
#include<stdexcept>

using namespace std;

istream& function(istream &is)
{
	int v;
	while (is >> v,!is.eof())
	{
		if (is.bad())
		{
			throw runtime_error("IO流错误");
		}
		if (is.eof())
		{
			cerr << "数据错误，请重试：" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << v << endl;
	}
	is.clear();
	return is;
}

int main()
{
	cout << "请输入一些整数，按Ctrl+Z结束" << endl;
	function(cin);

	system("pause");
	return 0;
}
