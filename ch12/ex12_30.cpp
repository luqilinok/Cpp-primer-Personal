#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class QueryResult;
class TextQuery {
public:
	using LineNo = vector<string>::size_type;  //定义一个类型成员来引用行号
	TextQuery(std::ifstream &);  //构造函数，逐行读取输入文件
	QueryResult query(const string&) const;  //接受一个string，返回一个QueryResult表示string出现的那些行

private:
	shared_ptr<vector<string>> input;    //输入文件
	std::map<string, shared_ptr<std::set<LineNo>>> result;  //单词到它所在行号的映射
};

TextQuery::TextQuery(std::ifstream &ifs) : input(new vector<string>)   //TextQuery的构造函数，读取输入文件并建立单词到行号的映射
{
	LineNo lineNo{ 0 };
	for (string line; std::getline(ifs, line); ++lineNo) {
		input->push_back(line);
		std::istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear()) {
			std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			auto &nos = result[word];
			if (!nos) nos.reset(new std::set<LineNo>);
			nos->insert(lineNo);
		}
	}
}

class QueryResult {
public:
	friend std::ostream& print(std::ostream &, const QueryResult&);
public:
	QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v) : word(s), nos(set), input(v) { }
private:
	string word;  //保存查询单词
	shared_ptr<std::set<TextQuery::LineNo>> nos;  //指向保存单词出现行号的set
	shared_ptr<vector<string>> input;  //指向保存输入文件的vector
};

QueryResult TextQuery::query(const string& str) const
{
	static shared_ptr<std::set<LineNo>> nodata(new std::set<LineNo>);
	auto found = result.find(str);  //found表示位置
	if (found == result.end()) return QueryResult(str, nodata, input);
	else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
	out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
	for (auto i : *qr.nos)
		out << "\t(line " << i + 1 << ") " << qr.input->at(i) << std::endl;
	return out;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do {
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	} while (true);
}
int main()
{
	std::ifstream file("../data/storyDataFile.txt");
	runQueries(file);
}
