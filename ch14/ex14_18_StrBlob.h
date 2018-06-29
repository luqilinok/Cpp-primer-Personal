#ifndef CP5_STRBLOB_H
#define CP5_STRBLOB_H

#include<iostream>
#include<vector>
#include<initializer_list>
#include<memory>
#include<exception>

#include <algorithm>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	using size_type = vector<string>::size_type;
	friend class ConstStrBlobPtr;
	friend class StrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);

public:
	StrBlob() :data(make_shared<vector<string>>()) {}
	StrBlob& operator=(const StrBlob&);

	StrBlob(StrBlob &&rhs)noexcept :data(std::move(rhs.data)) {}
	StrBlob& operator=(StrBlob &&)noexcept;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string&t) { data->push_back(t); }
	void push_back(string &&s) { data->push_back(std::move(s)); }

	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

private:
	void check(size_type, const string&) const;

	shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);

inline void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

inline string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline void StrBlob::check(size_type i, const string &msg) const
{
	if (i >= data->size()) throw std::out_of_range(msg);
}

class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator< (const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator> (const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) { }

	string& deref() const;
	StrBlobPtr& incr();

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;

	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator< (const StrBlobPtr&, const StrBlobPtr&);
bool operator> (const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);

inline string& StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
}


class ConstStrBlobPtr {
	friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator< (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator> (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &s, size_t sz = 0) : wptr(s.data), curr(sz) { }

	const string& deref() const;
	ConstStrBlobPtr& incr();

private:
	std::shared_ptr<vector<string>> check(size_t, const string&) const;

	std::weak_ptr<vector<string>> wptr;
	size_t curr;
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator< (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator> (const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

inline const string& ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

inline std::shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) throw std::out_of_range(msg);
	return ret;
}


bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const StrBlob &lhs, const StrBlob &rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator> (const StrBlob &lhs, const StrBlob &rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
	return !(lhs < rhs);
}



bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const StrBlobPtr &x, const StrBlobPtr &y)
{
	return x.curr < y.curr;
}

bool operator>(const StrBlobPtr &x, const StrBlobPtr &y)
{
	return x.curr > y.curr;
}

bool operator<=(const StrBlobPtr &x, const StrBlobPtr &y)
{
	return x.curr <= y.curr;
}

bool operator>=(const StrBlobPtr &x, const StrBlobPtr &y)
{
	return x.curr >= y.curr;
}


bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return !(lhs == rhs);
}

bool operator< (const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr > rhs.curr;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr <= rhs.curr;
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
	return lhs.curr >= rhs.curr;
}


StrBlob& StrBlob::operator=(const StrBlob &lhs)
{
	data = make_shared<vector<string>>(*lhs.data);
	return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs) noexcept
{
	if (this != &rhs) {
		data = std::move(rhs.data);
		rhs.data = nullptr;
	}

	return *this;
}



StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}

#endif // !CP5_STRBLOB_H
