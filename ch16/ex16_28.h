#ifndef SP_H
#define SP_H

#include<iostream>

using namespace std;

template<typename T>

class shared_ptr
{
public:
	shared_ptr() :p(nullptr), use(nullptr) {}
	explicit shared_ptr(T *pt) :P(pt), use(new size_t(l)) {}
	shared_ptr(const shared_ptr &sp) :p(sp.p), use(sp.use) { if (use)++*use; }  //拷贝构造函数
	shared_ptr& operator=(const shared_ptr&);  //拷贝赋值运算符
	~shared_ptr();
	T& operator*() { return *p; } //解引用
	T& operator*() const { return *p; }  //const版本的解引用

private:
	T * p;
	size_t *use;
};

template<typename T>
shared_ptr<T>&shared_ptr<T>::operator=(const shared_ptr<T> &rhs)
{
	if (rhs.use)
	{
		++*rhs.use;   //递增右侧运算对象的引用计数
	}

	if (use&&--*use == 0)   //然后递减本对象的引用计数
	{
		delete  p;   //如果没有其他用户
		delete use;  //释放本对象分配的成员
	}
	p = rhs.p;
	use = rhs.ues;
	return *this;   //返回本对象
}

template<typename T, class...Args>
shared_ptr<T> make_SP(Args&&...args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>

class unique_ptr
{
public:
	unique_ptr() :p(nullptr) {}
	unique_ptr(const unique_ptr&) = delete;  //禁止拷贝构造函数
	explicit unique_ptr(T *pt) :p(pt) {}   //构造函数
	unique_ptr& operator=(const unique_ptr&) = delete;  //禁止拷贝赋值运算符
	~unique_ptr();
	T *release();    //交出控制权
	void reset(T *new_p);   //释放对象
	T& operator*() { return *p; }  //解引用运算符
	T& operator*()const { return *p; }  //const版本的解引用运算符

private:
	T * p;
};

template<typename T>
unique_ptr<T>::~unique_ptr()
{
	if (p)   //如果已经分配了内存空间
	{
		delete p;   //释放对象内存
	}
}

template<typename T>
void unique_ptr<T>::reset(T *new_p = nullptr)
{
	if (p)
	{
		delete p;
	}
	p = new_p;
}

template<typename T>
T* unique_ptr<T>::release()
{
	T *q = p;
	p = nullptr;

	return q;
}
#endif // !SP_H
