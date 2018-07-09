#include<iostream>
#include<string>

using namespace std;

template<typename T,size_t N>

const T *my_begin(const T(&a)[N])
{
	return &a[0];
}

template<typename T,size_t N>

const T *my_end(const T(&a)[N])
{
	return &a[0] + N;
}
