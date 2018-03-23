#include<iostream>
#include<vector>
#include<string>


using namespace std;
using std::vector;

int main()
{
	vector<string> vec;
	for (string buffer;cin>>buffer;)
	{
		vec.push_back(buffer);
	}

	system("pause");
	return 0;
}
