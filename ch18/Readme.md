ex18_01

(a)异常对象r的类型是range_error
(b)被抛出的异常对象时对指针p解引用的结果，其类型与p的静态类型相匹配，为exception,如果写成throw p,则抛出的异常对象时exception*类型

ex18_02

new的作用是动态分配和初始化对象，即分配新的内存，因此在new操作后发生的异常会使得动态分配的数组没有被撤销，从而造成内存的泄漏

ex18_03

方法1：将有可能发生的异常的代码用try-catch语句进行捕获异常
void exercise(int *b,int *e)
{
  vector<int> v(b,e);
  int *p=new int[v.size()];
  try{
        ifstream in(“ints”);
  }
  catch
       {
          delete p;
  }
}

方法2：定义一个类来封装数组的分配和释放，以保证正确释放资源：
#include<iostream>
#include<fstream>
#include<vector>
#include<memory>

using namespace std;

class Resource
{
public:
	Resource(size_t sz) :r(new int[sz]) {}
	~Resource() { if (r) delete r; }

private:
	int *r;
};

void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	Resource res(v.size());
	ifstream in("ints");


}

ex18_04

该try块中使用的exception、runtime_error和overflow_error是标准库中定义的异常类，它们是因继承而相关的:runtime_error类继承exception类，overflow_error类继承runtime_error类，在使用来自继承层次的异常时，catch子句应该从最低派生类型到最高派生类型排序，以便派生类型的处理代码出现在catch之前，所以上述块中，catch子句的顺序错误

ex18_05

int main()
{
	try
	{
		//使用C++标准库
	}
	catch(const exception &e){
		cerr<<e.what()<<endl;
	}
	return 0;
}

ex18_06

(a)throw new exceptionType()  //动态创建一个异常对象并抛出其指针
(b)throw 8;  //被抛出的表达式为任意类型
(c)throw 11;   //被抛出的表达式为int类型的即可


ex18_09

Sales_data&
Sales_data::operator-=(const Sales_data &rhs)
{
	if(isbn()!=rhs.isbn())
		throw isbn_mismatch("wrong isbns",isbn(),rhs.isbn());
	units_sold -=rhs.units_sold;
	revenue -=rhs.revenue;
	return *this;
}

ex18_10

//处理异常
Sales_data item1,item2,sum;
while(cin>>item1>>item2){
   try{
   	sum=item1+item2;
	return sum;
      }catch(const isbn_mismatch &e){
      	cerr<<e.what()<<":left isbn("<<e.left<<") right isbn("<<e.right<<")"<<endl;
      }
}


//不处理异常

Sales_data item1,item2,sum;
while(cin>>item1>>item2)
{
	sum=item1+item2;
	return sum;
}

ex18_11

what函数是在catch异常后用于提取异常基本信息的虚函数，what函数是确保不会出现任何异常的，如果what函数继续产生异常，则将会产生抛出异常的死循环，所以what函数必须确保不抛出异常

ex18_12

将Query类以及Query_base类层次定义为命名空间chapter15的成员，并相应修改主程序中的代码（使用限定名引用这些类，或者使用相应的using声明）

ex18_13

通常，当需要声明局部与文件的实体时，可以使用未命名的命名空间，即在文件的最外层作用域中定义未命名的命名空间

ex18_14

将函数返回类型及函数名加上命名空间名字进行限定即可：
mathLib::MatrixLib::matrix mathLib::MatrixLib::operator*(const matrix & ,const matrix &){/* ...*/}

ex18_15

一个using指示使得特定命名空间中的所有名字都成为可见的；而一个using声明只能引入特定命名空间中的一个成员

ex18_16

如果命名空间Exercise的所有成员的using声明标记在位置1的地方，则Exercise中的成员在全局作用域中可见，using Exercise::ivar会导致ivar重复定义的编译错误，因为在全局作用域中也定义了一个同名变量；manip中的double dvar=3.1416声明了一个局部变量dvar，在函数体作用域中它将屏蔽Exercise::dvar,int iobj=limit+1声明了一个局部变量iobj，并用Exercise::limit+1的结果来对它进行初始化

如果命名空间Exercise的所有成员的using声明方在标记为位置2的地方，则manip中的double dvar=3.1416属于对变量dvar的重复定义，会出现编译错误，int iobj=limit+1声明了一个局部变量jobj，并用Exercise::limit加1的结果对其进行初始化，++ivar访问到的是Exercise::ivar，而++::ivar访问到的是全局变量ivar

如果命名空间Exercise的using指示放在标记为位置1的地方，则manip中的double dvar=3.1416声明了一个局部变量dvar,在函数体作用域中它将屏蔽Exercise::dvar;int iobj=limit+1;声明了一个局部变量iobj，并用Exercise::limit加1的结果对其进行初始化，++ivar访问到的是Exercise::ivar，而++::ivar访问的是全局变量ivar

如果命名空间Exercise的using指示放在标记为位置2的地方，则Exercise的成员看来好像是声明在全局作用域中的一样，manip中的double dvar=3.1416声明了一个局部变量dvar，在函数体作用域内它将屏蔽Exercise::dvar,int iobj=limit+1声明了一个局部变量iobj，并用Exercise::limit加1的结果对其进行初始化；++ivar出现二义性错误，因为编译器无法分辨是访问Exercise::ivar还是访问全局变量ivar，而++::ivar访问的是全局变量ivar

ex18_18

如果mem1是string类型的，那么编译器除了在常规作用域中查找匹配的swap函数之外，还会查找string所属的命名空间中是否有string类型的特定版本的swap函数，但是对string而言，找到的就是std::swap，完成两个字符串内容的交换

如果mem1是int类型，那么因为int类型是内置类型，没有特定版本的swap，所以只会在常规作用域中进行查找，由于using声明的作用，最终会调用std::swap来完成对int的交换

ex18_19

如果用std::swap(v1.mem1,v2.mem1),那么将直接使用标准库版本的swap，而不会查找特定版本的swap或常规作用域中的其他swap
