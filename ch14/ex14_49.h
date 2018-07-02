#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Date
{
public:
	explicit operator bool()
	{
		vector<vector<int>> days_per_month = {
			{31,28,31,30,31,30,31,31,30,31,30,31},
		{ 31,29,31,30,31,30,31,31,30,31,30,31 }
		};

		return 1 <= month && month <= 12 && 1 <= day && day <= days_per_month[isLeapYear() ? 1 : 0][month - 1];
	}
	bool isLeapYear()
	{
		return(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
	//其他成员
};
