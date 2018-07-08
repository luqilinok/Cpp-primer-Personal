#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include <string>
#include <vector>
#include <set>
#include<map>
#include <iostream>

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
	friend std::ostream& print(std::ostream&, const QueryResult&, int beg, int end);
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) { }
	std::set<line_no>::size_type size() const { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;  // word this query represents
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file;  //input file
};

std::ostream &print(std::ostream&, const QueryResult&);

class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
	void display_map();        // debugging aid: print the map
private:
	std::shared_ptr<std::vector<std::string>> file; // input file
													// maps each word to the set of the lines in which that word appears
	std::map<std::string,
		std::shared_ptr<std::set<line_no>>> wm;

	// canonicalizes text: removes punctuation and makes everything lower case
	static std::string cleanup_str(const std::string&);
};

class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no; // used in the eval functions
	virtual ~Query_base() = default;
private:
	// eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep is a string representation of the query
	virtual std::string rep() const = 0;
};

// interface class to manage the Query_base inheritance hierarchy
class Query
{
	// these operators need access to the shared_ptr constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);  // builds a new WordQuery
								// copy constructor
	Query(const Query& query) : q(query.q), uc(query.uc) { ++*uc; }
	Query& operator=(const Query& query); // copy assignment operator

										  // interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const
	{
		return q->eval(t);
	}
	std::string rep() const { return q->rep(); }
	~Query();
private:
	Query(Query_base* query) : q(query), uc(new int(1)) { }
	Query_base* q;
	int* uc;
};

inline std::ostream &operator<<(std::ostream &os, const Query &query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}

class WordQuery : public Query_base
{
	friend class Query; // Query uses the WordQuery constructor
	WordQuery(const std::string &s) : query_word(s) { }

	// concrete class: WordQuery defines all inherited pure virtual functions
	QueryResult eval(const TextQuery &t) const
	{
		return t.query(query_word);
	}
	std::string rep() const { return query_word; }
	std::string query_word;   // word for which to search
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)), uc(new int(1)) { }

inline Query::~Query()
{
	if (--*uc == 0)
	{
		delete q;
		delete uc;
	}
}

inline Query& Query::operator=(const Query& query)
{
	++*query.uc;
	if (--*uc == 0)
	{
		delete q;
		delete uc;
	}
	q = query.q;
	uc = query.uc;
	return *this;
}

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { }

	// concrete class: NotQuery defines all inherited pure virtual functions
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;
	Query query;
};

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) { }

	// abstract class: BinaryQuery doesn't define eval
	std::string rep() const {
		return "(" + lhs.rep() + " "
			+ opSym + " "
			+ rhs.rep() + ")";
	}

	Query lhs, rhs;    // right- and left-hand operands
	std::string opSym; // name of the operator
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") { }
	// concrete class: AndQuery inherits rep and defines the remaining pure virtual
	QueryResult eval(const TextQuery&) const;
};

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") { }
	QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}

inline Query operator~(const Query &operand)
{
	return new NotQuery(operand);
}

std::ifstream& open_file(std::ifstream&, const std::string&);
TextQuery get_file(int, char**);
bool get_word(std::string&);
bool get_words(std::string&, std::string&);
std::ostream &print(std::ostream&, const QueryResult&);

#endif
