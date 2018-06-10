#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc,char *argv[])
{
	ifstream in(argv[1]);
	if (!in)
	{
		cout << "打开输出文件失败！" << endl;
		exit(1);
	}

	unordered_map<string, size_t> word_count;
	string word;
	while (in>>word)
	{
		++word_count[word];
	}
	for (const auto &w:word_count)
	{
		cout << w.first << " 出现了" << w.second << " 次" << endl;
	}
	system("pause");
	return 0;
}
