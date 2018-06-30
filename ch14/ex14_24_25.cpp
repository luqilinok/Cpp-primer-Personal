#include<algorithm>
#include"ex14_24_25.h"

Date::Date(Size days)
{
	Size y400 = days / YtoD_400;
	Size y100 = (days - y400 * YtoD_400) / YtoD_100;
	Size y4 = (days - y400 * YtoD_400 - y100 * YtoD_100) / YtoD_4;
	Size y = (days - y400 * YtoD_400 - y100 * YtoD_100 - y4 * YtoD_4) / 365;
	Size d = days - y400 * YtoD_400 - y100 * YtoD_100 - y4 * YtoD_4 - y * 365;
	this->year = y400 * 400 + y100 * 100 + y4 * 4 + y;

	std::vector<Size>currYear = isLeapYear(this->year) ? monthsVec_1 : monthsVec_n;

	Size D_accumu = 0, M_accumu = 0;

	std::find_if(currYear.cbegin(), currYear.cend(), [&](Size m) {
		D_accumu += m;
		M_accumu++;

		if (d < D_accumu)
		{
			this->month = M_accumu;
			this->day = d + m - D_accumu;

			return true;
		}
		else
			return false;
	});
}

Date::Date(std::istream & is, std::ostream & os)
{
	is >> day >> month >> year; \
		if (is)
		{
			if (check(*this))
			{
				return;
			}
			else
			{
				os << "Invalid input!Object is default initialized ";
				*this = Date();
			}
		}
		else
		{
			os << "Invalid input!Object is default initialized ";
			*this = Date();
		}
}

Date::Date(const Date &d) :day(d.day), month(d.month), year(d.year) { }

Date::Date(Date && d) noexcept : day(d.day), month(d.month), year(d.year) { std::cout << "copy moving"; }

Date & Date::operator=(const Date & d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;

	return *this;
}

Date & Date::operator=(const Date && rhs) noexcept
{
	if (this != &rhs)
	{
		this->day = rhs.day;
		this->month = rhs.month;
		this->year = rhs.year;
	}
	std::cout << "moving=";
	return *this;
}

Date::Size Date::toDays() const
{
	Size result = this->day;
	std::vector<Size>currYear = isLeapYear(this->year) ? monthsVec_l : monthsVec_n;
	for (auto it = currYear.cbegin(); it != currYear.cend() + this->month - 1; ++it)
	{
		result += *it;
	}
	result += (this->year / 400)      * YtoD_400;
	result += (this->year % 400 / 100)  * YtoD_100;
	result += (this->year % 100 / 4)    * YtoD_4;
	result += (this->year % 4)        * YtoD_1;

	return result;
}

Date & Date::operator+=(Size offset)
{
	*this = Date(this->toDays() + offset);
	return *this;
}

Date Date::operator-=(Size offset)
{
	if (this->toDays() > offset)
	{
		*this = Date(this->toDays() - offset);
	}
	else
	{
		*this = Date();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Date & d)
{
	os << d.day << " " << d.month << " " << d.year;
	return os;
}

std::istream & operator>>(std::istream & is, Date & d)
{
	if (is)
	{
		Date input = Date(is, std::cout);
		if (check(input))
		{
			d = input;
		}
	}
	return is;
}

int operator-(const Date & lhs, const Date & rhs)
{
	return lhs.toDays() - rhs.toDays();
}

bool operator==(const Date & lhs, const Date & rhs)
{
	return(lhs.day == rhs.day) &&
		(lhs.month == rhs.month) &&
		(lhs.year == rhs.year);
}

bool operator!=(const Date & lhs, const Date & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Date & lhs, const Date & rhs)
{
	return lhs.toDays() < rhs.toDays();
}

bool operator<=(const Date & lhs, const Date & rhs)
{
	return(lhs < rhs) || (lhs == rhs);
}

bool operator>(const Date & lhs, const Date & rhs)
{
	return !(lhs <= rhs);
}

bool operator>=(const Date & lhs, const Date & rhs)
{
	return !(lhs < rhs);
}

Date operator-(const Date & lhs, Date::Size rhs)
{
	Date result(lhs);
	result -= rhs;

	return result;
}

Date operator+(const Date & lhs, Date::Size rhs)
{
	Date result(lhs);
	result += rhs;

	return result;
}
