#include<iostream>
#include<string>
#include<vector>

using namespace std;

class My_data
{
public:
	My_data(const string &s)
	{
		unsigned tag;
		unsigned format;
		format = tag = 0;

		//eg1:2/10/1994
		if (s.find_first_of("/")!=string::npos)
		{
			format = 0x01;
		}

		//eg2:Janunary 1,1990 or Jan 1,1990
		if ((s.find_first_of(',')>=4)&&s.find_first_of(',')!=string::npos)
		{
			format = 0x10;
		}
		else   //eg3:Jan 1 1900
		{
			if (s.find_first_of(',')>3&&s.find_first_of(' ')!=string::npos)
			{
				format = 0x10;
				tag = 1;
			}
		}
		switch (format)
		{
		case 0x01:
			day = stoi(s.substr(s.find_first_of("/")));
			month = stoi(s.substr(s.find_first_of("/") + 1, s.find_first_of("/") - s.find_first_of("/")));
			year = stoi(s.substr(s.find_last_of("/") + 1, 4));

			break;
		case 0x10:
			if (s.find_first_of("Jan") < s.size()) month = 1;
			if (s.find_first_of("Feb") < s.size()) month = 2;
			if (s.find_first_of("Mar") < s.size()) month = 3;
			if (s.find_first_of("Apr") < s.size()) month = 4;
			if (s.find_first_of("May") < s.size()) month = 5;
			if (s.find_first_of("Jun") < s.size()) month = 6;
			if (s.find_first_of("Jul") < s.size()) month = 7;
			if (s.find_first_of("Aug") < s.size()) month = 8;
			if (s.find_first_of("Sep") < s.size()) month = 9;
			if (s.find_first_of("Oct") < s.size()) month = 10;
			if (s.find_first_of("Nov") < s.size()) month = 11;
			if (s.find_first_of("Dec") < s.size()) month = 12;

			char chr = ',';
			if (tag==1)
			{
				chr = ' ';
			}
			day = stoi(s.substr(s.find_first_of("123456789"), s.find_first_of(chr) - s.find_first_of("123456789")));
			year = stoi(s.substr(s.find_last_of(' ') + 1, 4));
			break;
		}
	}
	void print()
	{
		cout << "day: " << day << " " << "month:" << month << " " << "year:" << year;
	}
private:
	unsigned year, month, day;

};

int main()
{
	My_data d("Jan 1 1900");
	d.print();
	return 0;
}

