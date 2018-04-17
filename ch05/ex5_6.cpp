#include<iostream>
#include<string>
#include<vector>

using namespace std;
using std::vector;
using std::string;

int main()
{
	int grade;
	const vector<string> scores = { "F", "D", "C", "B", "A", "A++" };
	while (cin>>grade)
	{
		string lettergrade = (grade < 60) ? scores[0] : scores[(grade-50)/10];
		lettergrade += (grade == 100 || grade < 60) ? " " : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : " ";
		cout << lettergrade << endl;
	}
	


	system("pause");
	return 0;
}
