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

typedef pair<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;

vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;  // initially empty
						  // for each store find the range of matching books, if any
	for (auto it = files.cbegin(); it != files.cend(); ++it)
	{
		// find the range of Sales_data that have the same ISBN
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second)
		{
			ret.push_back(make_pair(it - files.cbegin(), found));
		}
	}
	return ret;
}
