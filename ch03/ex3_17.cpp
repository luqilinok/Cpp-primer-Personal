#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string>vString;
	string s;
	char cont = 'y';
	cout << "请输入第一个词：" << endl;
	while (cin>>s)
	{
		vString.push_back(s);
		cout << "要继续输入吗？（y or n）" << endl;
		cin >> cont;
		if (cont !='y' &&cont !='Y')
		{
			break;
		}
		cout << "请输入下一个词：" << endl;
	}
	for (auto &mem:vString)
	{
		for (auto &c:mem)
		{
			c = toupper(c);
		}
		cout << mem << endl;
	}

	system("pause");

	return 0;
}
