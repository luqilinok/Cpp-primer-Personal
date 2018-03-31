#include<iostream>
#include<string>
#include<cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
	const char* cs1 = "Luqilin";
	const char* cs2 = "Shadow";
	auto result = strcmp(cs1, cs2);
	if (result==0)
	{
		cout << "same strings" << endl;
	}
	else if (result<0)
	{
		cout << "Luqilin<Shadow" << endl;
	}
	else
	{
		cout << "Luqilin>Shadow" << endl;
	}

	system("pause");
	return 0;
}
