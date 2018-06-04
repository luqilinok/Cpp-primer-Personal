#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	copy(vi.begin(), vi.end(), out_iter);

	list<int> li;
	vector<int>::reverse_iterator rend(vi.begin() + 2);  //将第3个位置转换为反向迭代器
	vector<int>::reverse_iterator rbegin(vi.begin() + 7);//将第8个位置转换为反向迭代器

	copy(rbegin, rend, back_inserter(li));  //用反向迭代器将元素逆序拷贝到list，back_inserter等价于push_back();
	copy(li.begin(), li.end(), out_iter);  //输出

	system("pause");
	return 0;
	

}
