#ifndef VEC_H
#define VEC_H

#include <memory>

template<typename T>
class Vec
{
public:
	Vec() :element(nullptr), first_free(nullptr), cap(nullptr) { }
	Vec(std::initializer_list<T> l);
	Vec(const Vec& v);

	Vec& operator =(const Vec& rhs);

	~Vec();

	void push_back(const T& t);

	std::size_t size() const { return first_free - element; }
	std::size_t capacity()const { return cap - element; }

	T* begin() const { return element; }
	T* end()   const { return first_free; }

	void reserve(std::size_t n);

	void resize(std::size_t n);
	void resize(std::size_t n, const T& t);

private:

	T * element;
	T* first_free;
	T* cap;

	std::allocator<T> alloc;

	void reallocate();
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
	void free();

	void wy_alloc_n_move(std::size_t n);

	std::pair<T*, T*> alloc_n_copy(T* b, T* e);
};

template<typename T>
Vec<T>::Vec(const Vec &v)
{
	std::pair<T*, T*> newData = alloc_n_copy(v.begin(), v.end());

	element = newData.first;
	first_free = cap = newData.second;
}

template<typename T>
Vec<T>::Vec(std::initializer_list<T> l)
{
	T* const newData = alloc.allocate(l.size());

	T* p = newData;
	for (const auto &t : l)
		alloc.construct(p++, t);

	// build data structure
	element = newData;
	first_free = cap = element + l.size();
}

template<typename T>
Vec<T>& Vec<T>::operator =(const Vec& rhs)
{
	std::pair<T*, T*> newData = alloc_n_copy(rhs.begin(), rhs.end());

	free();

	element = newData.first;
	first_free = cap = newData.second;

	return *this;
}

template<typename T>
Vec<T>::~Vec()
{
	free();
}

template<typename T>
void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template<typename T>
void Vec<T>::reserve(std::size_t n)
{
	if (n <= capacity()) return;

	wy_alloc_n_move(n);
}

template<typename T>
void Vec<T>::resize(std::size_t n)
{
	resize(n, T());
}

template<typename T>
void Vec<T>::resize(std::size_t n, const T &t)
{
	if (n < size())
	{
		for (auto p = element + n; p != first_free; )
			alloc.destroy(p++);

		first_free = element + n;
	}
	else if (n > size())
	{
		for (auto i = size(); i != n; ++i)
			push_back(t);
	}
}

template<typename T>
std::pair<T*, T*>
Vec<T>::alloc_n_copy(T *b, T *e)
{
	T* data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

template<typename T>
void Vec<T>::free()
{
	if (element)
	{
		for (auto p = first_free; p != element; )
			alloc.destroy(--p);

		alloc.deallocate(element, capacity());
	}
}

template<typename T>
void Vec<T>::wy_alloc_n_move(std::size_t n)
{
	std::size_t newCapacity = n;
	T* newData = alloc.allocate(newCapacity);

	T* dest = newData;
	T* old = element;
	for (std::size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*old++));

	free();

	element = newData;
	first_free = dest;
	cap = element + newCapacity;
}

template<typename T>
void Vec<T>::reallocate()
{
	std::size_t newCapacity = size() ? 2 * size() : 1;

	wy_alloc_n_move(newCapacity);
}

#endif // VEC_H
