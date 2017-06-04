#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool checkEmpty(string str) {
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] > ' ') return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	string s1, s2;
	for (;;) {
		getline(cin, s1);
		getline(cin, s2);
		reverse(s2.begin(), s2.end());
		reverse(s1.begin(), s1.end());
		if (s2.size() > 0 && !checkEmpty(s2))
		{
			string str1, str2;
			str1.append(s2.begin(), s2.begin() + s2.size() / 2);
			str2.append(s2.begin() + s2.size() / 2, s2.end());
			cout << str2 << str1 << endl;
		}
		if (s1.size() > 0 && !checkEmpty(s1))
		{
			string str1, str2;
			str1.append(s1.begin(), s1.begin() + s1.size() / 2);
			str2.append(s1.begin() + s1.size() / 2, s1.end());
			cout << str2 << str1 << endl;
		}
		if (cin.eof()) break;
	}
	return 0;
}