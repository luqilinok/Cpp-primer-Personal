#ifndef CP5_STRING_H_
#define CP5_STRING_H_

#include<iostream>
#include<memory>
#include<algorithm>

using namespace std;

class String
{
public:
	String() :String("") {}
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

private:
	std::pair<char*, char*>alloc_n_copy(const char*, const char*);
	void range_initializer(const char*, const char*);
	void free();
private:
	char *elements;
	char *end;
	std::allocator<char> alloc;
};
inline String::String(const char *s)
{
	char *s1 = const_cast<char*>(s);
	while (*s1)
	{
		++s1;
	}
	range_initializer(s, ++s1);
}
inline String::String(const String &rhs)
{
	range_initializer(rhs.elements, rhs.end);
	std::cout << "copy constructor" << std::endl;
}
inline String & String::operator=(const String &rhs)
{
	auto newstr = alloc_n_copy(rhs.elements, rhs.end);
	free();
	elements = newstr.first;
	end = newstr.second;
	std::cout << "copy-assignment" << std::endl;
	return *this;
}
inline String::~String()
{
	free();
}
std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	auto str = alloc.allocate(e - b);
	return{ str,std::uninitialized_copy(b,e,str) };
}
inline void String::range_initializer(const char *first, const char *last)
{
	auto newstr = alloc_n_copy(first, last);
	elements = newstr.first;
	end = newstr.second;
}
inline void String::free()
{
	if (elements)
	{
		std::for_each(elements, end, [this](char &c) {alloc.destroy(&c); });
		alloc.deallocate(elements, end - elements);
	}
}
#endif // !CP5_STRING_H_
