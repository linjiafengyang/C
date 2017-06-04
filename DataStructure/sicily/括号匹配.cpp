#include <iostream>
#include <stack>
using namespace std;
bool isLeft(char a) {
	return a == '{' || a == '[' || a == '(';
}
bool isRight(char a) {
	return a == '}' || a == ']' || a == ')';
}
bool isMatch(char a, char b) {
	return (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')');
}
int main(int argc, char const *argv[])
{
	int num;
	cin >> num;
	while (num--) {
		string s;
		cin >> s;
		stack<char> check;
		int flag = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!check.empty() && isRight(s[i])) {
				if (isMatch(check.top(), s[i])) {
					check.pop();
					continue;
				}
				else {
					break;
				}
			}
			if (isLeft(s[i]) || isRight(s[i])) check.push(s[i]);
		}
		if (check.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}