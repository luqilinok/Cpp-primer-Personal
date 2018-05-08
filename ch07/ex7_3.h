#include<string>

class Person
{
private:
	std::string name;
	std::string address;
public:
	std::string getName() const { return name; };
	std::string getAddress() const { return address; };
};

