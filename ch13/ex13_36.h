#ifndef FOLDER_H
#define FOLDER_H

#include<string>
#include<set>

class Message
{
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") :contents(str) {}
	Message(const Message&);  //拷贝构造函数
	Message& operator=(const Message&);  //拷贝赋值运算符
	~Message();   //析构函数

	void save(Folder&);   //从给定Folder集合中添加本Message
	void remove(Folder&); //从给定Folder集合中删除本Message

	void print_debug();

private:
	std::string contents;  //实际消息文本
	std::set<Folder*> folders;  //包含本Message的Folder

	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	void add_to_Folders(const Message&);  //将本Message添加到指向参数的Folder
	void remove_from_Folders();  //从folders中的每个Folder中删除本Message

	void addFldr(Folder *f) { folders.insert(f); }  //向Folder中添加Message
	void remFldr(Folder *f) { folders.erase(f); }   //从Folder中删除Message
};
void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}

class Folder
{
	friend class Message;
	friend void swap(Folder&, Folder&);
public:
	Folder() = default;  //默认构造函数
	Folder(const Folder &);  //拷贝构造函数
	Folder& operator=(const Folder &);  //拷贝赋值运算符
	~Folder();  //析构函数

private:
	std::set<Message*> msgs;

	void add_to_Message(const Folder&);
	void remove_from_Message();

	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }

	void swap(Folder&, Folder&);
};

#endif // !FOLDER_H
