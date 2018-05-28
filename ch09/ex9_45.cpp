#include<iostream>
#include<string>


using namespace std;

auto name_string(string &name, const string &pre, const string &suffix)
{
	name.insert(name.begin(), pre.begin(), pre.end());
	return name.append(suffix);

}

int main()
{
	string name("Wang");
	cout << name_string(name, "Mr.", " Jr") << endl;

	system("pause");
	return 0;
}
