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
	for (auto r_iter=vi.cend();r_iter!=vi.cbegin();--r_iter)
	{
		cout << *(r_iter-1) << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
