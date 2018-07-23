ex19_02

在分配空间时，可以将T *newelements = alloc.allocate(newcapacity);
重写为T * newelements=static_cast<T *>(operator new[](newcapacity * sizeof(T)));
在重新分配由Vector成员elements指向的旧空间时，alloc.deallocate(elements,end-elements);可以重写为：
operator delete[](elements);
