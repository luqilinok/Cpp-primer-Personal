/*练习1.9版本*/
#include<iostream>
int main() {
	int sum = 0;
	for (int i = 50; i <= 100; i++)

		sum += i;
	std::cout << "从50到100之间的整数之和为" << sum << std::endl;
	return 0;
}
/*练习1.10版本*/
#include<iostream>
int main() {
	int i;
	for (int i = 10; i >= 0; i--)

		std::cout << i << "";
	std::cout << std::endl;
	return 0;

}
/*练习1.11版本*/
#include<iostream>
int main() {
	std::cout << "请输入两个整数";
	std::cout << std::endl;
	int v1, v2;
	std::cin >> v1 >> v2;
	if (v1 > v2)//从大到小打印

		for (; v1 >= v2; v1--)
			std::cout << v1 << "";
	else
		for (; v1 <= v2; v1++)
			std::cout << v1 << "";
	std::cout << std::endl;
	return 0;
}
