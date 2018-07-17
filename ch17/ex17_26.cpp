#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const smatch& m)
{
	if (m[1].matched)
	{
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	}
	else
	{
		return !m[3].matched && m[4].str() == m[6].str();
	}
}

vector<PersonInfo>
getData(istream &is)
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;

	string line, word;

	vector<PersonInfo> people;

	while (getline(is, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		getline(record, line);
		sregex_iterator it(line.begin(), line.end(), r), end_it;
		for (it++; it != end_it; it++)
		{
			if (valid(*it))
			{
				info.phones.push_back("V" + it->str());
			}
			else
			{
				info.phones.push_back("I" + it->str());
			}
		}

		people.push_back(info);
	}

	return people;
}

ostream& process(ostream &os, vector<PersonInfo> people)
{
	for (const auto &entry : people)
	{
		ostringstream formatted, badNums;
		for (const auto &nums : entry.phones)
		{
			if (nums[0] == 'I')
			{
				badNums << " " << nums.substr(1) << endl;
			}
			else
			{
				formatted << " " << format(nums.substr(1)) << endl;
			}
		}
		if (badNums.str().empty())
		{
			os << entry.name << endl
				<< formatted.str() << endl;
		}
		else
		{
			cerr << "input error: " << entry.name
				<< " invalid number(s) " << badNums.str() << endl;
		}
	}

	return os;
}

int main()
{
	process(cout, getData(cin));
	return 0;
}
