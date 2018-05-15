#include<iostream>
#include<string>


class Book
{
public:

	Book(const std::string &name, const std::string &I, double pr, const std::string &a, const std::string &p)
	{
		BookName = name;
		ISBN = I;
		Price = pr;
		Author = a;
		Publisher = p;
	}
	Book():Book("","",0,"",""){ }
	Book(std::istream &in) :Book() { in >> BookName >> ISBN >> Price >> Author >> Publisher; }

private:
	std::string BookName, ISBN, Author, Publisher;
	double Price = 0.0;
};
