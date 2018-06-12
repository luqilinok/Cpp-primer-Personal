#include<iostream>
#include<memory>

using namespace std;

struct connection { };
struct destination{ };

connection connect(destination *pd)
{
	cout << "打开链接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭链接" << endl;
}

void f1(destination &d)
{
	cout << "用shared_ptr管理connect" << endl;
	connection c = connect(&d);

	shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });

	cout << endl;
}

int main(int argc, char *argv[])
{
	destination d;
	f1(d);

	system("pause");
	return 0;
}
