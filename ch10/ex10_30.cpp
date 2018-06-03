#include<iostream>
#include<iterator>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	istream_iterator<int> in_iter(cin), eof;
	vector<int> vi;
	while (in_iter!=eof)
	{
		vi.push_back(*in_iter);
	}
	sort(vi.begin(), vi.end());

	ostream_iterator<int> out_iter(cout, " ");
	copy(vi.begin(), vi.end(), out_iter);

	system("pause");
	return 0;
}
