#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> vi;
	int v;
	while (cin>>v)
	{
		vi.push_back(v);
	}
	for (auto r_iter=vi.crbegin();r_iter!=vi.crend();++r_iter)
	{
		cout << *r_iter << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
