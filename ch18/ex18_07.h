#include<iostream>
#include<initializer_list>
#include<vector>
#include<string>

using namespace std;

template<typename T> class Blob
{
public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	Blob();
	Blob(initializer_list<T> il) try :
		data(make_shared<vector<T>>(il))
	{
		//空函数体
	}
	catch (const std::bad_alloc &e) { handle_out_of_memory(e); }
	size_type size)() const{return data->size(); }
	bool empty()const { return data->empty(); }
	void push_back(const T &t) { data->push.back(t); }
	void push_back(T &t) { data->push_back(std::move(t); }
	void pop_back();
	T& back();
	T& operator[](size_type i);

private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

template<typename T>class BlobPtr
{
public:
	BlobPtr() :curr(0) {}
	BlobPtr(BlobPtr<T> &a, size_t sz = 0) try :
		wptr(a.data), curr(sz){}
}
catch (const std::bad_alloc &e) { handle_out_of_memory(e); }

T& operator*() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

BlobPtr& operator++();
BlobPtr& operator--();

private:
	std::shared_ptr<vector<T>> check(size_t, const string&) const;
	std::weak_ptr<vector<T>> wptr;
	size_t curr;
};
