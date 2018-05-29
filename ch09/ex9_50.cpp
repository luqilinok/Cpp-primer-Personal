#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc,char *argv[])
{
	vector<string> _string(5, "10");
	int sum1 = 0;
	double sum2 = 0.0;
	for (int i = 0; i < _string.size(); i++)
	{
		sum1 += stoi(_string[i]);
		sum2 += stod(_string[i]);

		cout << stod(_string[i]) << endl;
	}

	cout << "the sum of int is" << sum1 << endl;
	cout << "the sum of double is" << sum2 << endl;

	system("pause");
	return 0;
}
