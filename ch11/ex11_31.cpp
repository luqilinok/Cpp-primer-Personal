#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

void remove_author(multimap<string, string>&books, const string &author)
{
	auto pos = books.equal_range(author);  //查找给定作者的范围
	if (pos.first==pos.second)  //空范围，没有该读者
	{
		cout << "没有" << author << "这个作者" << endl << endl;
	}
	else
	{
		books.erase(pos.first, pos.second);  //删除该作者的所有著作
	}
}

void print_books(multimap<string, string> &books)
{
	cout << "当前数目包括:" << endl;
	for (auto book:books)   //遍历所有书籍，打印书籍的作者及名字
	{
		cout << book.first << ",《" << book.second << "》" << endl;
	}
	cout << endl;
}

int main(int argc,char *argv[])
{
	multimap<string, string> books;
	books.insert({ "金庸","天龙八部" });
	books.insert({ "金庸","射雕英雄传" });
	books.insert({ "paul","west fanals" });

	print_books(books);
	remove_author(books, "张三");
	remove_author(books, "paul");
	print_books(books);

	system("pause");
	return 0;
}
