#include<iostream>
int main()
{
	int sum = 0, value = 0;
	//读取数据知道遇到文件尾，计算所有读入的值的和
	while (std::cin >> value)
		sum += value;//等价于sum = sum+value
	std::cout << "Sum is: " << sum << std::endl;
	system("pause");
	return  0;
}
