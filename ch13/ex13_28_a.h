#ifndef EX13_28_H
#define EX13_28_H

#include<string>

using std::string;

class TreeNode
{
public:
	TreeNode() :value(string()), count(int(1)), left(nullptr), right(nullptr) { }  //默认构造函数
	TreeNode(const TreeNode &rhs) :value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) {}  //拷贝构造函数
	TreeNode& operator=(const TreeNode &rhs);//拷贝赋值运算符
	~TreeNode(); //析构函数

private:
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
};

#endif // !EX13_28_H
