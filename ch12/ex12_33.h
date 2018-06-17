#ifndef CP5_ex12_33_h
#define CP5_ex12_33_h

#include"ex12_22.h"
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include<sstream>
#include<algorithm>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
	TextQuery(std::ifstream &);
	QueryResult query(const string&) const;
private:
	StrBlob file;
	std::map<string, shared_ptr<std::set<StrBlob::size_type>>> result;
};

TextQuery::TextQuery(std::ifstream &ifs)
{
	StrBlob::size_type lineNo{ 0 };
	for (string line; std::getline(ifs, line); ++lineNo) {
		file.push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			// avoid read a word followed by punctuation(such as: word, )
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			// use reference avoid count of shared_ptr add.
			auto &nos = result[word];
			if (!nos) nos.reset(new std::set<StrBlob::size_type>);
			nos->insert(lineNo);
		}
	}
}
QueryResult TextQuery::query(const string& str) const
{
	// use static just allocate once.
	static shared_ptr<std::set<StrBlob::size_type>> nodate(new std::set<StrBlob::size_type>);
	auto found = result.find(str);
	if (found == result.end()) return QueryResult(str, nodate, file);
	else return QueryResult(str, found->second, file);
}
class QueryResult {
public:
	using ResultIter = std::set<StrBlob::size_type>::iterator;
	friend std::ostream& print(std::ostream &, const QueryResult&);
public:
	QueryResult(const string &s, shared_ptr<std::set<StrBlob::size_type>> set, const StrBlob& f) : word(s), nos(set), file(f) { }
	ResultIter begin() const { return nos->begin(); }
	ResultIter end() const { return nos->end(); }
	shared_ptr<StrBlob> get_file() const { return std::make_shared<StrBlob>(file); }
private:
	string word;
	shared_ptr<std::set<StrBlob::size_type>> nos;
	StrBlob file;
};

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
	for (auto it = qr.begin(); it != qr.end(); ++it) {
		ConstStrBlobPtr p(*qr.get_file(), *it);
		out << "\t(line " << *it + 1 << ") " << p.deref() << std::endl;
	}
	return out;
}

#endif
