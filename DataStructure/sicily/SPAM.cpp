#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isWordIllegal(char ch) {
	return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-' | ch == '_');
}
void substract(string &str, int mid, int &start, int &end) {
	start = end = mid;
	int len = str.length();
	for (int i = mid + 1; i < len; ++i)
	{
		if (isWordIllegal(str[i])) end++;
		else if (str[i] == '.') {
			if (i >= len) break;
			else if (isWordIllegal(str[i + 1])) end++;
			else break;
		}
		else break;
	}
	for (int i = mid - 1; i >= 0; i--) {
		if (isWordIllegal(str[i])) start--;
		else if (str[i] == '.') {
			if (i <= 0) break;
			else if (isWordIllegal(str[i - 1])) start--;
			else break;
		}
		else break;
	}
}
void solve(string &s) {
	int len = s.length();
	vector<string> vt;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '@')
		{
			int start, end;
			substract(s, i, start, end);
			string temp = s.substr(start, end - start + 1);
			if (start != i && end != i) vt.push_back(temp);
		}
	}
	for (int i = 0; i < vt.size(); ++i)
	{
		cout << vt[i] << endl;
	}
}
int main(int argc, char const *argv[])
{
	string s;
	while (getline(cin, s)) {
		solve(s);
	}
	return 0;
}