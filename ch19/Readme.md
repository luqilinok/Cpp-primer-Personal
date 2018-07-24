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

ex19_08

假设指针qb1和qb2的类型为Query_base*,则判断两个Query_base指针是否指向相同类型的typeid表达式如下：
typeid(* qb1)==typeid(* qb2)
判断该类型是否是AndQuery的typeid表达式如下:
typeid(* qb1)==typeid(AndQuery)

ex19_10

（a）class A*:因为pa是指向A类对象的指针，其类型为A*
（b）class A* :因为ra是A类对象的引用，表达式&ra求得ra的地址，该地址的类型是A*
（c）class A ：因为ra是A类对象的引用，其类型为A

ex19_11

指向数据成员的指针除了给出成员本身的类型外，还必须给出所属类的类型


ex19_12

指向Screen类的cursor成员的成员指针pm可定义如下：
pos Screen::* pm = &Screen::cursor;
可以使用成员指针解引用操作符(.* )从对象或引用获取成员，使用成员指针箭头操作符(->* )通过对象的指针获取成员
假设有如下对象定义：
Screen myScreen;
则可以这样通过成员指针pm获取Screen::cursor的值：
myScreen.* pm;
假设有如下对象指针定义：
Screen * pScreen;
则可以这样通过成员指针pm获取Screen::cursor的值
pScreen->* pm;