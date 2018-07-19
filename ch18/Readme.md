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