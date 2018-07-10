#ifndef SCREEN_H
#define SCREEN_H

#include<iostream>
#include<string>

using namespace std;

template<unsigned H, unsigned W>

class Screen
{
public:
	using pos = string::size_type;
	Screen() = default;
	Screen(char c) :contents(H*W, c) {}
	char get() const { return contents[cursor]; }
	Screen &move(pos r, pos c);

	friend ostream& operator<<(ostream &os, const Screen<H, W> &c)
	{
		unsigned int i, j;
		for (i = 0, i < c.height; i++)
		{
			os << c.contents.substr(0, W) << endl;
		}
		return os;
	}
	friend, istream& operator>>(istream &is, Screen &c)
	{
		char a;
		is >> a;
		string temp(H*W, a);
		c.contents = temp;
		return is;
	}
private:
	pos cursor = 0;
	pos height = H, width = W;
	string contents;
};

template<unsigned H, unsigned W>
inline Screeen<H, W>& Screen<H, W>::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}
#endif // !SCREEN_H
