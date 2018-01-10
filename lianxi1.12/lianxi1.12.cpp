#include<iostream>
int main() {
	int sum = 0;
	for (int i = -100; i <= 100; i++)
	{
		sum += i;  //等价于sum = sum+i；
	}
	std::cout << "Sum's final number is " << sum << std::endl;
	system("pause");
	return 0;
}
