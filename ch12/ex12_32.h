#ifndef EX12_32_H
#define EX12_32_H

#include"ex12_22.h"
using std::shared_ptr;

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>

class QueryResult;
class TextQuery
{
public:
	using LineNo = vector<string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const string&) const;

private:
	StrBlob file;
	std::map<string, shared_ptr<set<LineNo>>> result;
};

TextQuery::TextQuery(std::ifstream &ifs)
{
	StrBlob::size_type LineNo{ 0 };
	for (string line; std::getline(ifs, line); ++LineNo)
	{
		file.push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &nos = result[word];
			if (!nos) nos.reset(new std::set<StrBlob::size_type>);
			nos->insert(LineNo);
		}
	}
}
class QueryResult
{
public:
	friend std::ostream& print(std::ostream &, const QueryResult&);
public:
	QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v)::word(s), nos(set), input(v) { }

private:
	string word;
	shared_ptr<std::set<TextQuery::LineNo>> nos;
	shared_ptr < vector<string>> input;
};
QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<std::set<StrBlob::size_type>> nodata(new std::set<StrBlob::size_type>);
	auto found = result.find(str);
	if (found == result.end())return QueryResult(str, nodata, file);
	else return QueryResult(str, found->second, file);
}
std::ostream& print(std::ostream &out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
	for (auto i : *qr.nos) {
		ConstStrBlobPtr p(qr.file, i);
		out << "\t(line " << i + 1 << ") " << p.deref() << std::endl;
	}
	return out;
}
#endif // !EX12_32_H
