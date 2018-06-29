#ifndef CP5_CH14_EX14_15_H_
#define CP5_CH14_EX14_15_H_

#include <iostream>
#include <string>

class Book {
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);
	friend bool operator<(const Book&, const Book&);
	friend bool operator>(const Book&, const Book&);
	friend Book operator+(const Book&, const Book&);

public:
	Book() = default;
	Book(unsigned no, std::string name, std::string author, std::string pubdate, unsigned number) :no_(no), name_(name), author_(author), pubdate_(pubdate), number_(number) { }
	Book(std::istream &in) { in >> *this; }

	Book& operator+=(const Book&);

private:
	unsigned no_;
	std::string name_;
	std::string author_;
	std::string pubdate_;
	unsigned number_;
};

std::istream& operator>>(std::istream &in, Book &book)
{
	in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_ >> book.number_;
	return in;
}

std::ostream& operator<<(std::ostream &out, const Book &book)
{
	out << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_ << " " << book.number_ << std::endl;
	return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs)
{
	return lhs.no_ < rhs.no_;
}

bool operator>(const Book &lhs, const Book &rhs)
{
	return rhs < lhs;
}

Book& Book::operator+=(const Book &rhs)
{
	if (rhs == *this)
		this->number_ += rhs.number_;

	return *this;
}

Book operator+(const Book &lhs, const Book &rhs)
{
	Book book = lhs;
	book += rhs;
	return book;
}

#endif // CP5_CH14_EX14_15_H_
