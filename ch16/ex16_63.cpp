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

int main()
{
	vector<double> vd = { 1.1, 3.14, 2.2, 3.14, 3.3, 4.4 };
	cout << occur(vd, 3.14) << endl;

	vector<int> vi = { 0, 1, 2, 3, 4, 5 };
	cout << occur(vi, 0) << endl;

	vector<string> vs = { "Hello", "World", "!" };
	cout << occur(vs, string("end")) << endl;

	system("pause");
	return 0;
}
