#ifndef FOLDER_H
#define FOLDER_H

#include<string>
#include<set>

class Folder;

class Message
{
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") :contents(str) {}
	Message(const Message&);
	Message operator=(const Message&);
	Message(Message &&m);
	Message& operator=(Message&&);
	~Message();
	void save(Folder&);
	void remove(Folder&);

	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();

	void addFldr(Folder *f) { folders.insert(f); }
	void remFldr(Folder *f) { folders.erase(f); }
};

#endif // !FOLDER_H
