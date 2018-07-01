#include<iostream>
#include<vector>

class StrBlobPtr
{
	friend StrBlobPtr operator+(int n);
	friend StrBlobPtr operator-(int n);
public:
	//其他成员
private:
	//其他成员
};

StrBlobPtr StrBlobPtr::operator+(int n)
{
	auto ret = *this;
	ret.curr += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(int n)
{
	auto ret = *this;
	ret.curr -= n;
	return ret;
}
