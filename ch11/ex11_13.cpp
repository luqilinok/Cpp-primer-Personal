#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
	pair<string, int> p, p1;
	vector<pair<string, int>> vec, vec2, vec3;
	string word;
	int ival;
	while (cin>>word>>ival)
	{
		p = { word,ival };   //列表初始化
		vec.push_back(p);

		p1 = make_pair(word, ival);  //make_pair初始化
		vec2.push_back(p1);

		pair<string, int>p2(word, ival);  //构造函数初始化
		vec3.push_back(p2);
	}

	for (int i = 0; i != vec.size(); i++)
	{
		cout << (vec[i]).first << " " << (vec[i]).second << " " << endl;
	}
	for (int i = 0; i !=vec2.size(); i++)
	{
		cout << (vec2[i]).first << " " << (vec2[i]).second << " " << endl;
	}

	for (int i = 0; i != vec2.size(); i++)
	{
		cout << (vec3[i]).first << " " << (vec3[i]).second << " " << endl;
	}

	system("pause");
	return 0;
}
