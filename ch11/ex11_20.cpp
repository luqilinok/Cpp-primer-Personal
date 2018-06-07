#include<iostream>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	map<string, size_t> word_count;   //声明一个string映射到size_t的map
	string word;
	while (cin>>word)  
	{
		auto ret = word_count.insert({word,1});  //插入一个元素，关键字等于word，值为1
		if (!ret.second)   //	如果word已经在word_count容器中，递增迭代器	
		{
			++ret.first->second;
		}
	}

	for (const auto &w:word_count)   //打印结果
	{
		cout << w.first << " 出现了" << w.second << w.second << " 次" << endl;
	}

	system("pause");
	return 0;
}
