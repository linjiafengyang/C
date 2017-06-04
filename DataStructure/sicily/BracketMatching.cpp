#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	int test_number;
	cin >> test_number;
	while (test_number--) {
		string s;
		stack<char> ss;
		cin >> s;
		int n = s.length();
		char c;
		int flag = 1;
		for (int i = 0; i < n; ++i)
		{
			c = s[i];
			if (c == '(' || c == '[' || c == '{')
			{
				ss.push(c);
			}
			if (c == '}' || c == ']')
			{
				if (!ss.empty() && ss.top() == (c - 2))//ASCII码中[]和{}括号差2
				{
					ss.pop();
				}
				else {
					cout << "No" << endl;
					flag = 0;
					break;
				}
			}
			if (c == ')')
			{
				if (!ss.empty() && ss.top() == (c - 1))//ASCII码中()括号差1
				{
					ss.pop();
				}
				else {
					cout << "No" << endl;
					flag = 0;
					break;
				}
			}
		}
		if (flag == 0)
		{
			continue;
		}
		if (ss.empty())
		{
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}