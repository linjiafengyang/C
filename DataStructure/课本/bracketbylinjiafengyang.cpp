#include <iostream>
#include <stack>
using namespace std;
int main() {
	char n;
	stack<char> s;
	bool is_matched = true;
	while (is_matched && (n = cin.get()) != '\n') {
		if (n == '{' || n == '[' || n == '(')
		{
			s.push(n);
		}
		if (n == '}' || n == ']' || n == ')')
		{
			if (s.empty())
			{
				cout << "Unmatched closing bracket " << n << " detected." << endl;
				is_matched = false;//可以试试去掉这一句，然后运行输入(){[]
			}
			else {
				char temp;
				temp = s.top();
				s.pop();
				is_matched = (n == '}' && temp == '{') || (n == ']' && temp == '[')
								|| (n == ')' && temp == '(');
				if (!is_matched)
				{
					cout << "Bad match " << temp << n << endl;
				}
				else {
					cout << "Good match " << temp << n << endl;
				}
			}
		}
	}
	if (!s.empty())
	{
		cout << "Unmatched opening bracket(s) detected." << endl;
	}
}