#ifndef EX13_28_H
#define EX13_28_H

#include<string>

using std::string;


class BinStrTree
{
public:
	BinStrTree()：root(new TreeNode()) {}  //默认构造函数
	BinStrTree(const BinStrTree &bst) :root(new TreeNode(*bst.root)) {}  //拷贝构造函数
	BinStrTree& operator=(const BinStrTree &bst);//拷贝赋值运算符
	~BinStrTree() { delete root; }  //析构函数

private:
	TreeNode * root;
};

#endif // !EX13_28_H
