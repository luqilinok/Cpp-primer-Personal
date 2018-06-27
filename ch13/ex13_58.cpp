#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class  Foo
{
public:
	Foo sorted() && ;
	Foo sorted() const &;
private:
	vector<int> data;
};

Foo Foo::sorted() &&
{
	cout << "右值引用版本" << endl;
	sort(data.begin(), data.end());
	return *this;
}

inline Foo Foo::sorted() const &
{
	cout << "左值引用版本" << endl;
	Foo ret(*this);
	return ret.sorted();  //等价于return Foo(*this).sort();
}

int main(int argc, char *argv)
{
	Foo f;
	f.sorted();

	system("pause");
	return 0;
}
