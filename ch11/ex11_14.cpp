#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
	families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family, const string &child, const string &birthday)
{
	families[family].push_back({child,birthday});
}

int main(int argc, char *argv[])
{
	map<string, vector<pair<string, string>>> families;    //声明一个空的关联容器，为families

	add_family(families, "张");//初始化
	add_child(families, "张", "强", "1970-1-1");
	add_child(families, "张", "刚", "1980-1-1");
	add_child(families, "王", "五", "1990-1-1");

	for (auto f:families)  //进行输出
	{
		cout << f.first << " 家的孩子";
		for (auto c:f.second)
		{
			cout << c.first << "(生日" << c.second << "), ";   //families的第二个成员是vector<pair<string,string>>,所以c.first就是孩子的名，c.second是孩子的生日
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

