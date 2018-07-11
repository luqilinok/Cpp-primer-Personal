#include<iostream>
#include<string>
#include<algorithm>
#include<memory>
#include"sp_Blob.h"
#include"Blob.h"

using namespace std;

int main()
{
	Blob<string> b1;
	cout << b1.size() << endl;
	{
		Blob<string> b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << " " << b2.size() << endl;
	}
	cout << b1.size() << endl;
	for (size_t i = 0; i < b1.size(); ++i)
	{
		cout << b1.at(i) << " ";
	}
	cout << endl << endl;

	UP<int> u1(new int(42));
	cout << *u1 << endl;
	UP<int> u2(u1.release());

	system("pause");
	return 0;
}
