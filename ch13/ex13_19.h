#ifndef EX12_19_H
#define EX12_19_H

#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	Employee() { mysn = sn++; }
	Employee(const string &s) { name = s; mysn = sn++; }
	
	Employee(Employee &s) { name = e.name; mysn = sn++; }  //拷贝构造函数
	Employee& operator=(Employee &rhs) { name = rhs.name; return *this; }  //拷贝赋值运算符

	const string &get_name() { return name; }
	int get_mysn() { return mysn; }

private:
	static int sn;
	string name;
	int mysn;
};


#endif // !EX12_19_H

