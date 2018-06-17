#include<iostream>
#include"demo.h"

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	do {
		std::cout << "enter word to look for, or q to quit: ";
		string s;
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	} while (true);
}
int main()
{
	std::ifstream file("../data/storyDataFile.txt");
	runQueries(file);
}
