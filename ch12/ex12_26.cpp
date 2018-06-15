#include<iostream>
#include<string>
#include<memory>

using namespace std;

int main(int argc, char *argv[])
{
	allocator<string> alloc;
	auto const p = alloc.allocate(100);  //分配100个未初始化的string
	string s;
	string *q = p;  //q指向第一个string
	while (cin>>s&&q!=p+100)   //用s初始化*q
	{
		alloc.construct(q++, s);
	}
	const size_t size = q - p;  //记录读取了多少个string

	//使用数组
	for (size_t i = 0; i < size; i++)
	{
		cout << p[i] << " " << endl;
	}
	while (q!=p)   //使用完成后对每个构造的元素调用destroy来销毁它们
	{
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 100);

	system("pause");
	return 0;
}
