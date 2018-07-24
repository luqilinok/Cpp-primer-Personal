#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	vector<string> v;
	string a;
	while (getline(cin, a))
	{
		v.push_back(a);
	}
	auto m = count_if(v.begin(), v.end(), mem_fn(&std::string::empty));
	cout << "Using mem_fn,the number of empty lines" << m << endl;
	auto n = count_if(v.begin(), v.end(), bind(&std::string::empty, std::placeholders::_1));
	cout << "Using bind,the number of empty lines:" << n << endl;
	auto q = count_if(v.begin(), v.end(), [](std::string &tem) {return tem.empty();});
	cout << "Using lamba,the number of empty lines:" << q << endl;

	system("pause");
	return 0;
}
