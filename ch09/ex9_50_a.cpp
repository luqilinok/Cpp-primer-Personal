#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<string> vs = { "123","+456","-789" };
	int sum = 0;

	for (auto iter=vs.begin();iter!=vs.end();iter++)
	{
		sum += stol(*iter);
	}

	cout << "The sum is:" << sum << endl;

	system("pause");
	return 0;
}
