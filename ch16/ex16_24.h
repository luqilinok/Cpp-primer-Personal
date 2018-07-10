#ifndef BLOB_H
#define BLOB_H

#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

template<typename T> class Blob
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;

	Blob();
	Blob(initializer_list<T> il);
  
  //ex16_24补充说明的部分
	template<typename It>  //添加的构造函数，接受迭代器
	Blob(It b, It e);

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();

	T& back();
	T& operator[](size_type i);
private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

template<typename T>
inline Blob<T>::Blob() :data(make_shared<vector<T>>()) {}

template<typename T>
inline Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) {}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
inline T & Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T & Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
inline void Blob<T>::check(size_type i, const string & msg) const
{
	if (i >= data->size())
	{
		throw out_of_range(msg);
	}
}
//ex16_24补充的部分，接受迭代器
template<typename T>
template<typename It>
inline Blob<T>::Blob(It b, It e) :
	data(make_shared<vector<T>>(b, e)) {}

#endif // !BLOB_H
