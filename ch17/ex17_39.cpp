#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	fstream inOut(argv[1], fstream::ate | fstream::in | fstream::out); //以读写方式打开文件，并定位到文件尾
	if (!inOut)
	{
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}
	//inOut以ate模式打开，因此一开始就定义到其文件尾
	auto end_mark = inOut.tellg();  //记住原文件的尾位置
	inOut.seekg(0, fstream::beg);   //重定位到文件开始
	size_t cnt = 0;  //字节计数累加器
	string line;  //保存输入中的每行
	//继续读取的条件：还未遇到错误且还在读取原数据
	while (inOut&&inOut.tellg() != end_mark && getline(inOut, line))
	{
		cout << line << " : " << line.size() << endl;
		cnt += line.size() + 1;  //加1表示换行符
		auto mark = inOut.tellg();  //记住读取位置
		inOut.seekp(0, fstream::end);  //将写标记移动到文件尾
		inOut << cnt;   //输出累计的长度
		if (mark != end_mark)   //如果不是最后一行，打印一个分隔符
		{
			inOut << " ";
		}
		inOut.seekg(mark);  //恢复读位置
	}
	inOut.seekp(0, fstream::end);
	inOut << "\n";   //在文件结尾输出一个换行符

	system("pause");
	return 0;
}
