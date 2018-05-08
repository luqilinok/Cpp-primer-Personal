#include<iostream>
#include<string>

struct Person
{
	std::string const& getName() const { return name; };
	std::string const& getAddress() const { return address; };

	std::string name;
	std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
		return is;
}
std::ostream &print(std::ostream &os, Person &person)
{
	os << person.name << " " << person.address;
	return os;
}
