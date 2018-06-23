#include<iostream>
#include<initializer_list>

using namespace std;

inline StrVec::StrVec(initializer_list<string> il)
{
  newdata=alloc_n_copy(il.begin(),il.end());
  elements=newdata.first;
  firstfree=cap=newdata.second;
}
