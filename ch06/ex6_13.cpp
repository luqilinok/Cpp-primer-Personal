#include<iostream>
using namespace std;

void a(int i)
{
	++i;
	cout << i << endl;  //当将s=0赋值给i时，输出1
}
void b(int &j)
{
	++j;
	cout << j << endl;  //当将t=10赋值给j时，输出11
}


int main()
{
	int s = 0, t = 10;
	a(s);  // 输出0
	cout << s << endl;
	b(t);
	cout << t << endl;  //输出11

	system("pause");
	return 0;
}

