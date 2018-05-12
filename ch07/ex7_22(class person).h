#include<iostream>
#include<string>

class Person
{
	//为Person的非成员函数所做的友元声明
	friend std::istream &read(std::istream &is, Person &person);
	friend std::ostream &print(std::ostream &os, Person &person);
	//其他成员及访问说明符与之前一致
public:
	Person() = default;
	Person(const std::string &sname, const std::string saddress) :name(sname), address(saddress) { }
	Person(std::istream&is) { read(is, *this); }
	std::string getName() const { return name; }
	std::string getAddress() const { return address; }

private:
	std::string name;
	std::string address;
};

//Person接口的非成员组成部分的声明(如果希望类的用户能够调用某个友元函数，必须在友元函数之外再专门对函数进行一次声明，如下所示)
std::istream &read(std::istream&, Person&);//read函数
std::ostream &print(std::ostream&,const Person&);//print函数

