#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>

using namespace std;

istream& function(istream &is)
{
	string v;
	while (is >> v, !is.eof())
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
	ostringstream msg;
	msg << "C++ Primer 第五版" << endl;
	istringstream in(msg.str());
	function(in);

	system("pause");
	return 0;
}
