#include<iostream>
#include<vector>

using namespace std;
using  std::cout;
using  std::cin;
using std::endl;
using std::vector;


int main()
{
	vector<int> ivec;
	for (int i = 0; cin>>i; )
	{
		ivec.push_back(i);
	}
	if (ivec.empty())
	{
		cout << "input at least one integer" << endl;

		system("pause");
		return -1;
	}
	auto size = ivec.size();
	if (size%2!=0)
	{
		size = size / 2 + 1;
	}
	else
	{
		size /= 2;
	}
	for (int i = 0; i!=size; ++i)
	{
		cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
