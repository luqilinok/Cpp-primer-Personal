#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
#include<stdexcept>
#include<random>
#include<time.h>

using namespace std;

map<string, vector<string>> buildMap(ifstream &map_file)  //允许多种转换方法
{
	map<string, vector<string>> trans_map;
	string key;
	string value;

	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
		{
			trans_map[key].push_back(value.substr(1));
		}
		else
		{
			throw runtime_error("no rule for" + key);
		}
	}
	return trans_map;
}

const string &transform(const string &s, const map<string, vector<string>> &m)
{
	static default_random_engine e(time(0));  // 随机数引擎，静态变量保持状态
	auto map_it = m.find(s);
	if (map_it != m.end())
	{
		uniform_int_distribution<unsigned> u(0, map_it->second.size() - 1);  //随机数分布
		return map_it->second[u(e)];  //随机选择一种转换方式
	}
	else
	{
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);

	cout << "Here is our transformation map:\n\n";
	for (auto entry : trans_map)
	{
		cout << "key: " << entry.first << "\tvalue ";
		for (auto s : entry.second)
		{
			cout << s << ", ";
		}
		cout << endl;
	}

	cout << endl << endl;

	string text;
	while (getline(input, text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		throw runtime_error("wrong number of arguments");
	}
	ifstream map_file(argv[1]);
	if (!map_file)
	{
		throw runtime_error("no transformation file");
	}

	ifstream input(argv[2]);
	if (!input)
	{
		throw runtime_error("no input file");
	}
	word_transform(map_file, input);
	return 0;
}
