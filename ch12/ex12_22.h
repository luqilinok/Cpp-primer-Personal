#ifndef EX12_22_H
#define EX12_22_H
#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<exception>

using namespace std;

class ConstStrBlobPtr;

class StrBlob
{
public:
	friend class ConstStrBlobPtr;
	using size_type = vector<string>::size_type;

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

	StrBlob():data(make_shared<vector<string>>()){ }
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){ }

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string &t) { return data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string& front() const 
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	const string& back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg) const
	{
		if (i>data->size())
		{
			throw out_of_range(msg);
		}
	}
};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() :curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) { } // should add const
	bool operator!=(ConstStrBlobPtr& p) { return p.curr != curr; }
	const string& deref() const 
	{ // return value should add const
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	ConstStrBlobPtr& incr() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const
	{
		auto ret = wptr.lock();
		if (!ret)
		{
			throw runtime_error("unbound StrBlobPtr");
		}
		if (i>=ret->size())
		{
			throw out_of_range(msg);
		}

		weak_ptr<vector<string>> wptr;
		size_t curr;
	}
};

#endif // !EX12_22_H
