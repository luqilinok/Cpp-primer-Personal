ex19_02

在分配空间时，可以将T *newelements = alloc.allocate(newcapacity);
重写为T * newelements=static_cast<T *>(operator new[](newcapacity * sizeof(T)));
在重新分配由Vector成员elements指向的旧空间时，alloc.deallocate(elements,end-elements);可以重写为：
operator delete[](elements);

ex19_03

使用dynamic_cast操作符时，如果运行时实际绑定到引用或指针的对象不是目标类型的对象（或其公有派生类的对象），则dynamic_cast失败,所以：
(b)dynamic_cast转换失败，因为目标类型是C，但pb实际指向的不是C类对象，而是一个B类（C的基类）对象
(c)会编译失败，因为A是D的一个二义基类

ex19_05

如果无法为基类增加虚函数，就可以使用dynamic_cast代替虚函数
