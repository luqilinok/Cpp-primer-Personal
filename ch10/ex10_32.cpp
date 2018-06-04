#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<iterator>
#include"Sales_item.h"

using namespace std;

int main()
{
	vector<Sales_item> vs;
	istream_iterator<Sales_item> in_iter(cin);   //从cin读取Sales_item
	istream_iterator<Sales_item> eof;   //istream尾后迭代器
	
	//读入交易记录，存入vector
	while (in_iter!=eof)
	{
		vs.push_back(*in_iter++);
	}
	if (!vs.empty())
	{
		cerr << "No data?!" << endl;
		return -1;
	}
	sort(vs.begin(), vs.end(), compareIsbn);  //将交易记录按ISBN排序

	auto l = vs.begin();
	while (l!=vs.end())
	{
		auto item = *l;  //相同ISBN的交易记录中的第一个，在后续记录中查找第一个ISBN与item不同者
		auto r = find_if(l + 1, vs.end(), [item](const Sales_item &item1) {return item1.isbn() != item.isbn(); });  //获取一个迭代器，指向第一个满足isbn不相等的元素（r是迭代器）
		cout << accumulate(l + 1, r, item) << endl;  //将范围(l,r)之间的交易记录累加并输出
		l = r;  //指向下一段交易记录中的一个
	}

	system("pause");
	return 0;
}
