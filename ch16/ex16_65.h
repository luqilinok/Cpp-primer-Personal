#include<iostream>
#include<string>

using namespace std;


template<>
std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}

template<>
std::string debug_rep(const  char *cp)
{
	return debug_rep(std::string(cp));
}
