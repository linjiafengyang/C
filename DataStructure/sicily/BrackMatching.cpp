#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isLeftBracket(char a) {
	if (a == '(' || a == '[' || a == '{')
	{
		return true;
	}
	return false;
}
bool isRightBracket(char a) {
	if (a == ')' || a == ']' || a == '}')
	{
		return true;
	}
	return false;
}
int main() {
	int num;
	cin >> num;
	int count = 0;
	while (num--) {
		string s;
		cin >> s;
		stack<char> v;
		int length = s.length();
		int flag = 0;
		for (int i = 0; i < length; ++i)
		{
			if (isLeftBracket(s[i]))
			{
				v.push(s[i]);
			}
			else {
				if (!isRightBracket(s[i]))
				{
					continue;
				}
				if (!v.empty())
				{
					if (v.top() == '(')
					{
						if (s[i] != ')')
						{
							break;
						}
						else {
							v.pop();
							continue;
						}
					}
					if (v.top() == '[')
					{
						if (s[i] != ']')
						{
							break;
						}
						else {
							v.pop();
							continue;
						}
					}
					if (v.top() == '{')
					{
						if (s[i] != '}')
						{
							break;
						}
						else {
							v.pop();
							continue;
						}
					}
				}
				else {
					if (isRightBracket(s[i]))
					{
						v.push('a');
						break;
					}
				}
			}
		}
		if (!v.empty())
		{
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
}