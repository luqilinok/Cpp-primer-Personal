#include<iostream>
#include<string>

class MyClass
{
public:
	std::string* operator->() const
	{
		return ptr->operator->();
	}

private:
	StrBlobPtr * ptr;
};
