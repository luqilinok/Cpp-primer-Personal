#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> ivec;
	cout << "ivec:size:" << ivec.size() << " capacity:" << ivec.capacity() << endl;

	for (vector<int>::size_type ix=0;ix!=24;++ix)
	{
		ivec.push_back(ix);
	}

	cout << "add ivec:size:" << ivec.size() << " add capacity:" << ivec.capacity() << endl;
	ivec.reserve(50);
	cout << "second add ivec:size:" << ivec.size() << " second add capacity:" << ivec.capacity() << endl;

	while (ivec.size()!=ivec.capacity())
	{
		ivec.push_back(0);
	}
	cout << "third add ivec:size:" << ivec.size() << " third add capacity:" << ivec.capacity() << endl;

	ivec.push_back(42);
	cout << " fourth  add ivec:size:" << ivec.size() << " fourth add capacity:" << ivec.capacity() << endl;

	ivec.shrink_to_fit();
	cout << "changed ivec:size:" << ivec.size() << " changed capacity:" << ivec.capacity() << endl;

	system("pause");
	return 0;
}
