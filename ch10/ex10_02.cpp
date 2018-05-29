#include<iostream>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

int main()   //读取string序列存入list
{
	list<string> ls{"aa","aaa","aa","cc"};
	auto times = count(ls.cbegin(), ls.cend(), "aa");

	cout << "the times of aa is " << times << endl;
	system("pause");
	return 0;
}
