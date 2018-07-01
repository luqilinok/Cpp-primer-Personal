#include<iostream>
#include<string>

using namespace std;
class ReadString
{
public:
	ReadString(istream &is = cin):is(is){}
	std::string operator()()
	{
		string line;
		if (!getline(is,line))
		{
			line = " ";
		}
		return line;
	}
private:
	istream & is;
};


