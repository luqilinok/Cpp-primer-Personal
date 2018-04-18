#include<iostream>

using namespace std;

int main()
{
	unsigned int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
	unsigned int spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
	char ch;
	while (cin.get(ch))
	{
		switch (ch)
		{
		case 'a':
		case'A':
			++aCnt;
			break;
		case'e':
		case'E':
			++eCnt;
			break;
		case'i':
		case'I':
			++iCnt;
			break;
		case'o':
		case'O':
			++oCnt;
			break;
		case'u':
		case'U':
			++uCnt;
			break;
		case' ':
			++spaceCnt;
			break;
		case'\t':
			++tabCnt;
			break;
		case'\n':
			++newlineCnt;
			break;
		}
	}
	cout << "Number of vowel a(A): \t" << aCnt << endl;
	cout << "Number of vowel e(E): \t" << eCnt << endl;
	cout << "Number of vowel i(I): \t" << iCnt << endl;
	cout << "Number of vowel o(O): \t" << oCnt << endl;
	cout << "Number of vowel u(U): \t" << uCnt << endl;
	cout << "Number of vowel space:\t" << spaceCnt << endl;
	cout << "Number of vowel \t:\t" << tabCnt << endl;
	cout << "Number of vowle \n:\t" << newlineCnt << endl;

	system("pause");
	return 0;
}
