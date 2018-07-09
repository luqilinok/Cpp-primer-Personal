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

#endif // !BLOB_H
