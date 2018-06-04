#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

int main()
{
	std::list<int> lst = { 1, 2, 3, 4, 0, 5, 6 };
	auto found_0 = std::find(lst.crbegin(), lst.crend(), 0);
	std::cout << std::distance(found_0, lst.crend()) << std::endl;
	
	system("pause");
	return 0;
}
