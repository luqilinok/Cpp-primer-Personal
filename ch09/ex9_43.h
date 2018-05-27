#include<iostream>
#include<string>

using namespace std;

void replace_with(string &s,const string &oldVal,const string &newVal)
{
	for (auto iter=s.begin();iter<=s.end()-oldVal.size();)
	{
		if (oldVal == string{iter,iter+oldVal.size()})   //如果s中有oldVal的部分
		{
			iter = s.erase(iter, iter + oldVal.size());  //c.eraser(b,e);删除迭代器b和e指定范围内的元素
			iter = s.insert(iter, newVal.begin(), newVal.end()); //c.insert(p,b,e);将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前
			iter += newVal.size();
		}
		else  //如果s中没有oldVal的部分
		{
			++iter;
		}
	}
}
