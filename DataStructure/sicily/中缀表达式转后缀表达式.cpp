#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isOperation(char operation) {
	if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '%')
	{
		return true;
	}
	return false;
}
int rank(char operation) {
	if (operation == '*' || operation == '/' || operation == '%')
	{
		return 3;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	stack <char> op;
	string str;
	cin >> str;
	int i;
	int len = str.length();
	for (i = 0; i < len; i++) {
		if (!isOperation(str[i]))
		{
			cout << str[i];
		}
		else {
			if (op.empty())
			{
				op.push(str[i]);
			}
			else {
				while (!op.empty() && rank(op.top()) >= rank(str[i])) {
					cout << op.top();
					op.pop();
				}
				op.push(str[i]);
			}
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}