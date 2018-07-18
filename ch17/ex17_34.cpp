#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

bool get_status()
{
	return false;
}

int main()
{
	bool b;
	cout << "default bool values:" << true << " " << false
		<< "\nalpha bool values: " << boolalpha
		<< true << " " << false << endl;

	bool bool_val = get_status();
	cout << boolalpha
		<< bool_val
		<< noboolalpha;
	cout << endl;

	const int ival = 15, jval = 1024;

	cout << "default: " << 20 << " " << 1024 << endl;
	cout << "octal: " << oct << 20 << " " << 1024 << endl;
	cout << "hex: " << hex << 20 << " " << 1024 << endl;
	cout << "decimal" << dec << 20 << " " << 1024 << endl;
	cout << noshowbase;

	cout << 10.0 << endl;
	cout << showpoint << 10.0
		<< noshowpoint << endl;

	cout << showpos << 10.0 << endl;
	cout << noshowpos << 10.0 << endl;

	cout << uppercase << showbase << hex
		<< "printed in hexadecimal: " << 20 << " " << 1024
		<< nouppercase << noshowbase << dec << endl;

	int i = -16;
	double d = 3.14159;
	// 补白第一列，使用输出中最小12个位置
	cout << "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	// 补白第一列，左对齐所有列
	cout << left
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< right; // 恢复正常对齐
				  // 补白第一列，右对齐所有列
	cout << right
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	// 补白第一列，但补在域的内部
	cout << internal
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n';
	// 补白第一列，用#作为补白字符
	cout << setfill('#')
		<< "i: " << setw(12) << i << "next col" << '\n'
		<< "d: " << setw(12) << d << "next col" << '\n'
		<< setfill(' '); // 恢复正常的补白字符

	cout << unitbuf; 		// 所有输出操作后都会立即刷新缓冲区
	cout << "default format: " << 100 * sqrt(2.0) << '\n'
		<< "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
		<< "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
		//<< "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
		//<< "use defaults: " << defaultfloat << 100 * sqrt(2.0)
		<< "\n\n";
	cout << nounitbuf; 		// 回到正常的缓冲方式

	cout << "hi!" << endl;   	// 输出hi和一个换行，然后刷新缓冲区
	cout << "hi!" << flush; 	// 输出hi，然后刷新缓冲区，不附加任何额外字符
	cout << "hi!" << ends;   	// 输出hi和一个空字符，然后刷新缓冲区

	char ch;
	cin >> noskipws; // 设置cin读取空白符
	while (cin >> ch)
		cout << ch;
	cin >> skipws; // 将cin恢复到默认状态，从而丢弃空白符

	return 0;
}
