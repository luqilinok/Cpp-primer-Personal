#include<iostream>
#include<algorithm>
#include<set>
#include"Quote.h"

using namespace std;

class Basket
{
public:
	void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }   //Basket使用合成的默认构造函数和拷贝控制成员
	double total_receipt(std::ostream&) const;

private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }   //该函数用于比较shared_ptr,multiset成员会用到它
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };   //multiset保存多个报价，按照compare成员排序
};

double Basket::total_receipt(ostream &os) const
{
	double sum = 0.0;   //保存实时计算出的总价格
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))   //iter指向ISBN相同的一批元素中的第一个，upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	{
		sum += print_total(os, **iter, items.count(*iter));   //我们知道在当前的Basket中至少有一个该关键字的元素，打印该书籍对应的项目
	}
	os << "Total Sale:" << sum << endl;  //打印最终的总价格
	return sum;
}
