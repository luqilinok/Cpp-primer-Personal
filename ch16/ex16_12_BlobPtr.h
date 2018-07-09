#ifndef BLOBPTR_H
#define BLOBPTR_H

#include<iostream>
#include<vector>
#include<memory>
#include"Blob.h"

using namespace std;

template<typename> class BlobPtr;

template<typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs);

template<typename T> class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(BLob<T> &a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}

	BlobPtr& operator++();
	BlobPtr& operator--();
private:
	shared_ptr<vector<T>> check(size_t, const string&) const;
	weak_ptr<vector<T>> wptr;
	size_t curr;
};

#endif // !BLOBPTR_H

template<typename T>
inline bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock())
	{
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.i < rhs.i;
}

template<typename T>
inline bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.wptr.lock() != rhs.wptr.lock())
	{
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.i == rhs.i;
}

template<typename T>
inline BlobPtr & BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlob");
	++curr;
	return *this;
}

template<typename T>
inline BlobPtr & BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");

	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator ++(int)
{
	BlobPtr ret = *this;
	++*this;

	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator --(int)
{
	BlobPtr ret = *this;
	--*this;

	return ret;
}
