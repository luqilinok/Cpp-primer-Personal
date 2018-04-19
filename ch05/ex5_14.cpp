#include<iostream> 
#include<string>
#include<vector>

using namespace std;
using std::vector;

int main()
{
	string Now_string, before_string, max_repeatstring;  //用Now_string表示当前字符串，before_string表示前一个字符串，max_repeatstring表示字符串最大的重复次数
	int currCnt = 1, maxCnt = 0;  //currCnt表示当前字符串出现的次数，maxCut表示出现次数最多的字符串数量
	while (cin>>Now_string)
	{
		if (Now_string==before_string)
		{
			++currCnt;
			if (currCnt>maxCnt)
			{
				maxCnt = currCnt;
				max_repeatstring = Now_string;
			}
		}
		else  //如果当前字符串和前一个字符串不一致，重置currCnt
		{
			currCnt = 1;
		}
		before_string = Now_string;   //更新before_string方便下一次循环使用
	}
	if (maxCnt>1)
	{
		cout << "出现最多的字符串是：" << max_repeatstring
			<< " 次数是" << maxCnt << endl;
	}
	else
	{
		cout << "每个字符串都出现了一次" << endl;
	}

	system("pause");
	return 0;

}
