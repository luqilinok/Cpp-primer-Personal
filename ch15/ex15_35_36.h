#ifndef QUERY_H
#define QUERY_H

#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
class TextQuery;
//QueryResult保存查询的结果
class QueryResult
{
public:
	typedef vector<string>::size_type line_no;//保存出现的行号，使用类型别名
	friend ostream& operator<<(ostream&, const QueryResult&);//输出查询结果

public:
	QueryResult(const string& s, shared_ptr<std::set<line_no>> set,
		shared_ptr<vector<string>> v)
		: word(s), nos(set), input(v)
	{
	}

private:
	string word;//查询的单词
	shared_ptr<std::set<line_no>> nos;//用set保存出现的行号，自动排序
	shared_ptr<vector<string>> input;//输入文件vector的指针
};

//TextQuery接受输入文件，并保存，生成map
class TextQuery
{
public:
	/*using line_no = vector<string>::size_type;//C++11新标准，可以使用typedef代替*/
	typedef vector<string>::size_type line_no;

	TextQuery(ifstream&);//接受输入文件的构造函数
	QueryResult query(const string&) const;//具体的查询函数

private:
	shared_ptr<vector<string>> input;//保存输入的vector的智能指针
	map<string, shared_ptr<set<line_no>>> result;//map保存单词出现的行和列
};

//抽象基类Query_base，用于派生
class Query_base
{
	friend class Query;
private:
	//纯虚函数，返回与当前Query匹配的QueryResult
	/*virtual QueryResult eval(const TextQuery&) const = 0;*/
	//纯虚函数，保存用于查询的string
	virtual string rep() const = 0;
protected:
	/*using line_no = vector<string>::size_type;//C++11新标准，可以使用typedef代替*/
	typedef vector<string>::size_type line_no;
	virtual ~Query_base() /*= default*/;//C++11新标准，不加
};

//查询基类 Query
class Query
{
	//定义运算符函数
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const string&s);//新的构造函数，查询单词
	//接口函数
	// 	QueryResult eval(const TextQuery &t) const
	// 	{
	// 		return q->eval(t);//查询结果
	// 	}//事先无需定义
	string rep() const
	{
		return q->rep();//查询单词
	}
private:
	Query(shared_ptr<Query_base> query) :q(query) {}//构造函数，接受一个Query_base的指针
	shared_ptr<Query_base> q;//保存一个指向基类的指针，私有成员
};

std::ostream &operator<<(std::ostream &os, const Query query)
{
	return os << query.rep();
}

//基础查询单词类
class WordQuery :public Query_base
{
	//所有成员皆为private,
	friend class Query;//Query需要使用其构造函数
	WordQuery(const string &s) :Query_word(s) { cout << "WordQuery" << endl; }//初始化

	QueryResult eval(const TextQuery& t) const
	{
		return t.query(Query_word);
	}//纯虚函数，必须重写
	string rep() const
	{
		return Query_word;
	}//纯虚函数，必须重写
	string Query_word;
};
inline Query::Query(const string &s) :q(new WordQuery(s)) { cout << "Query" << endl; }//程序顺序执行，所用之对象必须进行声明

																					  //NotQuery类，取反的query
class NotQuery :public Query_base
{
	friend Query operator~(const Query&);
	NotQuery(const Query&q) :query(q) { cout << "NotQuery" << endl; }//构造函数

	string rep()
	{
		return "~(" + query.rep() + ")";//表示不需要查询的单词
	}
	QueryResult eval(const TextQuery&);
	Query query;
};
// inline Query operator~(const Query&operand)
// {
// 	return shared_ptr<Query_base>(new NotQuery(operand));
// }

//BinaryQuery类，一个抽象基类，因为继承了基类的纯虚函数eval()
class BinaryQuery :public Query_base
{
protected:
	BinaryQuery(const Query&l, const Query&r, string s) :lhs(l), rhs(r), opSym(s) { cout << "BinaryQuery" << endl; }//构造函数
	string rep() const
	{
		cout << "Binary_rep" << endl;//36题
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	string opSym;//运算符的名字
};

//AndQuery类,继承自抽象基类BinaryQuery
class AndQuery :public BinaryQuery
{
protected:
	friend Query operator&(const Query&, const Query&);//之前定义的运算符
	AndQuery(const Query&left, const Query&right) :BinaryQuery(left, right, "&") { cout << "AndQuery" << endl; }//构造函数
																												//返回查询结果的函数
	QueryResult eval(const TextQuery&);
};
// inline Query operator&(const Query&lhs, const Query&rhs)
// {
// 	return shared_ptr<Query_base>(new AndQuery(lhs,rhs));//在未定义纯虚函数eval()时，为抽象基类，不可实例化
// }

//OrQuery类,继承自抽象基类BinaryQuery
class OrQuery :public BinaryQuery
{
protected:
	friend Query operator|(const Query&, const Query&);//之前定义的运算符
	OrQuery(const Query&left, const Query&right) :BinaryQuery(left, right, "|") { cout << "OrQuery" << endl; }//构造函数
	//返回查询结果的函数
	QueryResult eval(const TextQuery&);
};
// inline Query operator|(const Query&lhs, const Query&rhs)
// {
// 	return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
// }

#endif QUERY_H
