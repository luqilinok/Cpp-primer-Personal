#include<iostream>
int main() {
	int sum = 0, val = 1;
	//只要val的值小于等于10，while循环就会继续执行下去
	while (val <= 10)
	{
		sum = sum + val;  //将sum+val赋予sum
		val = val + 1;        //将val加1
	}
	std::cout << "Sum of 1 to 10 inclusive is "
		<< sum << std::endl;
	return 0;
}
