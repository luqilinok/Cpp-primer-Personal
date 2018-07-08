ex15_01

虚成员就是虚函数，虚函数就是在类中被声明为virtual的成员，基类希望这种成员在派生类中重定义，除了构造函数之外，任意非static成员都可以为虚函数

ex15_02

protected受保护的成员，基类希望它的派生类有权访问该成员，同时禁止其他用户访问，而private即使是其派生类也不能访问


ex15_04

(a)是错误的，不能用类本身作为类的基类
(b)是正确的
(c)声明类时，不可以包含派生列表

ex15_08

静态类型：表达式的静态类型在编译时总是已知的，它是变量声明时的类型或表达式生成的类型；
动态类型：动态类型则是变量或表达式表示的内存中的对象的类型，动态类型直到运行时才可知

ex15_09

基类的静态类型可能和其动态类型是不一致的，例子如下：
    Bulk_quote bulk;
    Quote *pQuote=&bulk;
    Quote &rQuote=bulk;
    double print_total(ostream &os,const Quote &otem,size_t n);
    
ex15_10

ifstream是从istream中派生而来的，是一个对象，所以能够正常使用

ex15_12

override：在C++11标准中，可以使用override关键字来说明派生类中的虚函数，这么做的好处可以更加清晰的告诉编译器我们想要覆盖掉原来已存在的虚函数，如果定义了一个函数与基类中的名字相同但是形参列表不同，在不适用override关键字时这种函数的定义是合法的，在使用了override关键字之后，这种行为是非法的，编译器会报错
final：如果我们将某个函数定义成final，则不允许后续的派生类覆盖这个函数，否则会报错
因此同时将一个成员函数声明成override和final能够让我们的意图更加清晰

ex15_13

成员函数的函数体中避免虚函数的问题，因为这会导致函数的自我调用，导致无限循环，此处派生类的print()函数中使用的print()函数会自动被解析为对自身的调用。所以应加上作用域限定符,具体例子请看ex15_13


ex15_14

(a)bobj.print();用的是基类的print函数
(b)dobj.print();用的是派生类的print函数
(c)bp1->name();用的是基类的name函数
(d)bp2->name();用的是派生类中基类的name函数
(e)br1.print();用的是基类的print函数
(f)br2.print();用的是派生类的print函数

ex15_17

错误信息显示：不能实例化抽象类

ex15_18

只有d1和dd1才能够赋值，这是因为：只有当派生类公有地继承基类时，用户代码才能使用派生类向基类的转换；也就是说，如果派生类继承基类的方式是受保护的或者私有的，则用户代码不能使用该转换
    本题中，只有d1和dd1类是公有的继承基类，故只有它们才能完成向基类的转换

ex15_19

Derived_from_Private:private Priv_Derv这个类的函数是不合法的，原因如下：
1.无论派生类以什么方式继承基类，派生类的成员函数和友元函数都能使用派生类向基类的转换；派生类向其直接基类的类型转换对于派生类的成员和函数来说永远都是可访问的
2.如果派生类继承基类的方式是公有的或者受保护的，则派生类的成员和友元可以使用派生类向基类的类型转换，反之，如果派生类继承基类的方式是私有的，则不能使用

ex15_21

对(b)中的几何图元组织继承一个继承层次：
(1) 公共基类Figure，表示几何图元
(2)类Rectangle、Circle、Sphere和Cone分别表示矩形、圆、球形和圆锥等图元，这些类可以定义为Figure类的派生类


ex15_23

如果D1类需要覆盖它继承而来的fcn函数，应该将D1类中的fcn函数修改为int fcn()
如果匹配了Base中的定义，那么该节的那些调用语句中p2->fcn(42)这一条语句将会报错

ex15_24

作为基类使用的类应该具有虚析构函数，以保证在删除执行动态分配对象的基类指针时，根据指针实际指向的对象所属的类型运行适当的析构函数
虚析构函数可以为空，即不执行任何操作，一般而言，析构函数的主要作用是清除本类中定义的数据成员，如果该类没有定义指针类的成员，则使用合成版本即可，如果该类定义了指针成员，则一般需要自定义析构函数用来对指针成员进行适当的清除操作，因此，如果有虚析构函数必须执行的操作，则就是清除本类中定义的数据成员的操作

ex15_25

因为Disc_quote的默认构造函数会运行Quote的默认构造函数，而Quote的默认构造函数会完成成员的初始化操作；
如果删除该构造函数，那么Bulk_quote的默认构造函数就无法完成初始化的操作了


ex15_29

程序产生的结果是不一样的，因为当通过Quote类型的对象调用虚函数net_price时，没有进行动态绑定，调用的是基类Quote的版本，当通过传入Quote对象的智能指针shared_ptr调用net_price版本时，实际上依赖于指针所指对象的动态类型，即实行了动态绑定，调用的是派生类Bulk_quote类中定义的版本

ex15_31

已经上传图片到本文件夹，名字是ex15_31.png,所以回答如下：
(a)共创建了12个对象：其中6个Query_base对象以及其相关联的句柄。6个Query_base对象分别是3个WordQuery对象，一个NOtQuery对象，1个AndQuery对象，一个OrQuery对象
(b)和(a)是相同的
(c)共创建了14个对象，其中7个Query_base对象及其相关联的句柄，7个Query_base对象分别是4个WordQuery对象，2个AndQuery对象，1个OrQuery对象

ex15_32

Query类没有定义自己的拷贝/移动控制成员，所以进行拷贝控制操作时，执行默认的语义，Query类中的成员是Query_base的一个智能指针shared_ptr，因此:
拷贝：调用合成的拷贝构造函数，将智能指针q的内容复制到新对象的对应成员，使智能指针q计数+1;
移动：调用合成的移动构造函数，将智能指针q的内容移动到新对象的对应成员，使智能指针q指向NULL;
赋值：调用合成的拷贝赋值运算符，将智能指针q的内容替换为参数对象的对应成员的内容，使q计数-1，并让参数计数+1;
摧毁：调用合成的析构函数，清理自身，并调用q的析构函数，使计数-1;

ex15_33

Query_base是一个虚基类，不允许直接声明其对象。当它的派生类对象进行这些操作的时候，会调用Query_base的响应控制成员，而Query_base没有定义自己的拷贝/移动控制成员，实际上它没有任何数据成员，无需定义这些操作，因此进行这些操作的时候，执行默认的语义，什么都不会发生

ex15_34

(a)处理表达式Query("fiery")&Query("bird")|Query("wind")所执行的构造函数如下：
1: Query::Query(const std::string& s) 

2: WordQuery::WordQuery(const std::string& s) 
3: AndQuery::AndQuery(const Query& left, const Query& right);
4: BinaryQuery(const Query&l, const Query& r, std::string s);
5: Query::Query(std::shared_ptr<Query_base> query) 2次
6: OrQuery::OrQuery(const Query& left, const Query& right);
7: BinaryQuery(const Query&l, const Query& r, std::string s);


8: Query::Query(std::shared_ptr<Query_base> query) 2次

(b) 运算符"<<"会调用Query的rep成员，Query.rep()调用的是OrQuery的rep(因为初始化对象q时使用的是值是"|"运算符返回的Query，而该对象的智能指针q指向的是一个OrQuery对象)，而OrQuery并没有定义rep成员，所以直接使用直接基类BinaryQuery的rep成员

(c)q调用的是OrQuery的eval函数，因为是虚函数，且使用引用调用，需动态绑定
