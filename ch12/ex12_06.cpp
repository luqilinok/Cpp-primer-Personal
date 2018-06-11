#include<iostream>
#include<vector>
#include<new>

using namespace std;

vector<int> *new_vector(void)
{
	return new(nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
	int v;

	while (cin>>v)
	{
		pv->push_back(v);
	}
}

void print_ints(vector<int> *pv)
{
	for (const auto &v : *pv)
	{
		cout << v << " ";
	}
	cout << endl;
}


int main(int argc, char *argv[])
{
	vector<int> *pv = new_vector();
	if (!pv)
	{
		cout << "内存不足!" << endl;
		return -1;
	}
	read_ints(pv);
	print_ints(pv);

	delete pv;
	pv = nullptr;

	system("pause");
	return 0;
}
