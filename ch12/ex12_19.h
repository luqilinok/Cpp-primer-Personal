#ifndef CP5_EX12_19_H
#define CP5_EX12_19_H

#include<vector>
#include<string>
#include<initializer_list>
#include<memory>
#include<stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
public:
	friend class StrBlobPtr;
	using size_type = vector<string>::size_type;

	StrBlob():data(make_shared<vector<string>>()){ }
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){ }
	
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	StrBlobPtr begin() { return StrBlobPtr(*this); }
	StrBlobPtr end()
	{
		auto ret = StrBlobPtr(*this, data->size());
		return ret;
	}
	//front、back、pop_back、push_back操作访问vector中的元素
	void push_back(const string &t) { return data->push_back(t); }
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	
	string &front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string &front() const  //不能在一个常量对象上调用普通的成员函数，因此要在成员函数的参数列表后面加上const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const string &back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const
	{
		if (i>data->size())
		{
			throw out_of_range(msg);
		}
	}
};

class StrBlobPtr
{
public:
	StrBlobPtr():curr(0){ }
	StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz){ }
	bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
	string& deref() const  //解引用
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr()  //前置递增
	{
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

private:
	shared_ptr<vector<string>> check(size_t i, const string &msg) const
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
	}
	weak_ptr<vector<string>> wptr;
	size_t curr;
};

#endif // !CP5_EX12_19_H
