#include<iostream>
#include<memory>

using namespace std;

struct destination {};
struct connection{};

connection connect(destination *pd)
{
	cout << "打开链接" << endl;
	return connection();
}

void disconnect(connection c)
{
	cout << "关闭连接" << endl;
}

void end_connection(connection *p)
{
	disconnect(*p);
}

void f1(destination &d)  //用shared_ptr来管理链接的打开和关闭
{
	cout << "用shared_ptr管理connect：" << endl;
	connection c = connect(&d);

	shared_ptr<connection> p(&c, end_connection);

	cout << endl;
}

int main(int argc, char *argv[])
{
	destination d;

	f1(d);

	system("pause");
	return 0;
}
