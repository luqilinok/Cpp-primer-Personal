#include<iostream>
#include<string>

using namespace std;
using std::string;

string make_plural(size_t ctr, const string &word, const string &ending ="s")  ////此处觉得题目描述有误，应该是第三个形参赋予"s"，应为是字符串
{
	return(ctr > 1) ? word + ending : word;
}

int main()
{
  //success情况比较特殊，因为其复数形式是es，所以需要三个实参
	cout << "success的单数形式是：" << make_plural(1, "success", "es") << endl;
	cout << "success的复数形式是：" << make_plural(2, "success", "es") << endl;
  //failure就是普通的复数情况，所以只需要头两个实参就够了
	cout << "failure的单数形式是：" << make_plural(1, "failure") << endl;
	cout << "failure的复数形式是：" << make_plural(2, "failure") << endl;

	system("pause");
	return 0;
}
