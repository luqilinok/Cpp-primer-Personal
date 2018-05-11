#include<iostream>
#include<string>

struct Person
{
	//新增的构造函数
	Person() = default;
	Person(const std::string &sname, const std::string saddress) :name(sname), address(saddress) { }
	Person(std::istream &is) { read(is, *this); }
	//之前已有的其他成员
	std::string name;
	std::string address;

	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
};

//read函数
std::istream &read(std::istream &is,Person &person)
{
	is >> person.name >> person.address;
	return is;
}

//print函数
std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name << person.address;
	return os;
}

