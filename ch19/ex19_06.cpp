#include<iostream>
#include<typeinfo>

using namespace std;

class Query_base
{
public:
	Query_base() {}
	virtual ~Query_base() {}
};

class BinaryQuery :public Query_base
{
public:
	BinaryQuery() {}
	virtual ~BinaryQuery() {}
};

class AndQuery :public BinaryQuery
{
	AndQuery() {}
	virtual ~AndQuery() {}
};

int main()
{
	Query_base *qb = new Query_base;
	if (dynamic_cast<AndQuery*>(qb) != NULL)
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "failure" << endl;
	}

	system("pause");
	return 0;
}
