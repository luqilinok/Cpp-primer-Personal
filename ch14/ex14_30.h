#include<iostream>
#include<string>

class StrBlobPtr
{
public:
	std::string& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	std::string* operator->() const
	{
		return &(this->operator*());
	}
	//其他成员

private:
	//其他成员
};

class ConstStrBlobPtr
{
public:
	const std::string& operator*() const
	{
		auto p = check(curr, "deference past end");
		return (*p)[curr];
	}

	const std::string*operator->()const
	{
		return &(this->operator*());
	}
private:
	//其他成员
};
