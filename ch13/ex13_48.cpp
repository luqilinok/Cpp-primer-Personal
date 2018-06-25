#include"demo.h"
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char *argv[])
{
	vector<String> vec;
	String s1("Hello");
	String s2 = s1;
	vec.push_back(s1);
	vec.push_back(s2);

	system("pause");
	return 0;
}
