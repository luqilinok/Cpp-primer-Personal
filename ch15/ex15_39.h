#ifndef QUERY_H
#define QUERY_H

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<memory>

using namespace std;

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
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
	std::string sought;  //
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file;  //input file
};

class TextQuery

{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
	void display_map();

private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;

	static string cleanup_str(string&);
};

class Query_base
{
	friend class Query;
public:
	using line_no = TextQuery::line_no;  //用于eval函数
	virtual ~Query_base() = default;

private:
	virtual QueryResult eval(const TextQuery&) const = 0; //eval返回与当前Query匹配的QueryResult
	virtual string rep() const = 0;  //rep是表示查询的一个string
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string &s) :q(new WordQuery(s)) { cout << "Query::Query(const std::string& s) where s=" << endl; }
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	string rep() const { cout << "Query::rep()\n"; return q->rep(); }
private:
	shared_ptr<Query_base> q;
	Query(shared_ptr<Query_base> query) :q(query) { cout << "Query::Query(std::shared_ptr<Query_base> query)\n"; }
};

class WordQuery :public Query_base
{
	friend class Query;
	WordQuery(const string &s) :query_word(s) { cout << "WordQuery" << endl; }

	QueryResult eval(const TextQuery &t) const override { return t.query(query_word); }
	string rep() const override { cout << "WordQuery::rep()\n"; return query_word; }

	string query_word;
};

class NotQuery :public Query_base
{
	friend Query operator~(const Query &operand);
	NotQuery(const Query &q) :query(q) { cout << "NotQuery::NotQuery()\n"; }
	string rep() const override { cout << "NotQuery::rep()\n"; return "~+" + query.rep() + ")"; }

	QueryResult eval(const TextQuery &) const override;
	Query query;
};

class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, string s) :lhs(l), rhs(r), opSym(s) { cout << "BinaryQuery" << endl; }
	string rep() const override { cout << "BinaryQuery::rep()\n"; return "(" + lhs.rep() + " " + opSym + " " + rhs.rep + ")"; }

	Query lhs, rhs;
	string opSym;
};

class AndQuery :public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "&") { cout << "AndQuery::AndQuery()\n"; }

	QueryResult eval(const TextQuery &) const override;
};

class OrQuery :public BinaryQuery
{
	friend Query operator|(const Query &, const Query &);
	OrQuery(const Query &left, const Query &right) :BinaryQuery(left, right, "|") { cout << "OrQuery::OrQuery\n"; }

	QueryResult eval(const TextQuery &) const override;
};

#endif // !QUERY_H
