#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

template<typename T>
int occur(vector<T> &vec, const T &v)
{
	int ret = 0;

	for (auto a : vec)
	{
		if (a == v)
		{
			ret++;
		}
	}
	return ret;
}

//为了特例化一个模板，原模板的声明必须在作用域中

template <>
int occur(vector<char *> &vec, char * const &v)
{
	int ret = 0;

	for (auto a : vec)
	{
		if (!strcmp(a, v))  //strcmp比较两个字符串
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	vector<char *> vp;
	vp.push_back(new char[6]);
	vp.push_back(new char[6]);
	vp.push_back(new char[2]);
	strcpy(vp[0], "Hello");
	strcpy(vp[1], "World");
	strcpy(vp[2], "!");
	char *w = new char[6];
	strcpy(w, "World");
	cout << occur(vp, w) << endl;
	delete w;
	delete vp[2];
	delete vp[1];
	delete vp[0];

	system("pause");
	return 0;
}
