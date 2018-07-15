#include<iostream>
#include<utility>
#include<vector>
#include<string>
#include<algorithm>
#include<exception>
#include<fstream>
#include<numeric>
#include<tuple>

#include"Sales_data.h"

using namespace std;

bool lt(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

class matches
{
public:
	matches(vector<Sales_data>::size_type n, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> f) : num(n), first(f.first), last(f.second) {}
	vector<Sales_data>::size_type get_num() const { return num; }
	vector<Sales_data>::const_iterator get_first() const { return first; }
	vector<Sales_data>::const_iterator get_last() const { return last; }
private:
	vector<Sales_data>::size_type num;
	vector<Sales_data>::const_iterator first, last;
};

vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			ret.push_back(matches(it - files.cbegin(), found));
		}
	}
	return ret;
}
