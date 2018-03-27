#include <iostream>
#include <vector>

using std::vector; 
using std::cout; 
using std::cin;
using std::endl; 


int main()
{
	vector<int> ivec;
	for (int i;cin>>i;)
	{
		ivec.push_back(i);
	}
	if (ivec.empty())
	{
		cout << "input at least one integer." << endl;
		system("pause");
		return -1;
	}
	if (ivec.size()==1)
	{
		cout << "only one integer " << ivec[0] << ", it doesn't have any adjacent elements." << endl;
		system("pause");
		return -1;
	}
	for (int i = 0; i < ivec.size(); ++i)
	{
		cout << ivec[i] + ivec[i + 1] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
