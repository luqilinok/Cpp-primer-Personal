
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	istream_iterator<int> in_iter(cin);  //创建流迭代器从标准输入中读入整数
	istream_iterator<int> eof;  //尾后迭代器

	vector<int> vi;
	while (in_iter != eof)
	{
		vi.push_back(*in_iter++);  //存入vector并递增迭代器
	}

	sort(vi.begin(), vi.end());

	ostream_iterator<int> out_iter(cout, " ");

	unique_copy(vi.begin(), vi.end(), out_iter);

	system("pause");
	return 0;
}
