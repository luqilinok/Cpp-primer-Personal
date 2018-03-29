#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<unsigned> scores(11, 0);
	for (unsigned grade; cin >> grade;)
	{
		if (grade<=100)
		{
			++*(scores.begin() + grade / 10);
		}
	}
	for (auto s:scores)
	{
		cout << s << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
