#ifndef STRVEC_H
#define STRVEC_H

#include<string>
#include<iostream>
#include<utility>

using namespace std;

class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {}  //构造函数
	StrVec(const StrVec&);  //拷贝构造函数
	StrVec& operator=(const StrVec&);  //拷贝赋值运算符
	~StrVec();  //析构函数
	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	std::string *begin() const { return elements; }
	std::string *end() const { return first_free; }

private:
	static std::allocator<std::string> alloc;  //分配元素
	void chk_n_alloc()   //被添加元素的函数所使用
	{
		if (size() == capacity())
		{
			reallocate();
		}
	}
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();  //销毁元素并释放内存
	void reallocate();  //获取更多内存并拷贝已有元素
	std::string *elements;  //指向数组首元素的指针
	std::string *first_free;  //指向数组第一个空闲元素的指针
	std::string *cap;  //指向数组尾后位置的指针
};

inline StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

inline StrVec & StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

inline StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}
inline std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data,uninitialized_copy(b,e,data) };
}
inline void StrVec::free()
{
	if (elements)
	{
		for (auto p = first_free; p != elements; )
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}
inline void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;  //分配当前大小两倍的内存空间
	auto newdata = alloc.allocate(newcapacity);  //将数据从旧内存移动到新内存
	auto dest = newdata;  //指向新数组中下一个空闲位置
	auto elem = elements;  //指向旧数组中下一个元素
	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
		free();  //移动完元素后就释放旧的内存空间，更新数据结构，执行新元素
		elements = newdata;
		first_free = dest;
		cap = elements + newcapacity;
	}
}
#endif // !STRVEC_H
