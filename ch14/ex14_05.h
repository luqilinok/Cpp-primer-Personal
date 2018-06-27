#include<iostream>
#include<string>

class Book
{
	friend std::istream& operator>>(std::istream&, Book&);
	friend std::ostream& operator<<(std::ostream&, const Book&);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);

public:
	Book() = default;
	Book(unsigned no, std::string name, std::string author, std::string pubdata) :no_(no), name_(name), author_(author), pubdate_(pubdata) {}
	Book(std::istream &in) { in >> *this; }

private:
	unsigned no_;
	std::string name_;
	std::string author_;
	std::string pubdate_;
};

std::istream & operator>>(std::istream &in, Book &book)
{
	in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
	return in;
}

inline std::ostream & operator<<(std::ostream &out, const Book &book)
{
	out << book.no_ << " " << book.name_ << " " << book.author_ << " " << book.pubdate_;
	return out;
}

inline bool operator==(const Book &lhs, const Book &rhs)
{
	return lhs.no_ == rhs.no_;
}

inline bool operator!=(const Book &lhs, const Book &rhs)
{
	return !(lhs == rhs);
}
