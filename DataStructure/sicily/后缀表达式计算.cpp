#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;
int charToInterger(char c) {
	return c - 'a' + 1;
}
double calculate(const string& input) {
	stack<double> s;
	for (int i = 0; i < input.length(); ++i)
	{
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			double post = s.top();
			s.pop();
			double pre = s.top();
			s.pop();
			switch(input[i]) {
				case '+':
				s.push(pre + post);
				break;
				case '-':
				s.push(pre - post);
				break;
				case '*':
				s.push(pre * post);
				break;
				case '/':
				s.push(pre / post);
				break;
			}
		}
		else if (input[i] >= 'a' && input[i] <= 'z') {
			s.push(charToInterger(input[i]));
		}
	}
	return s.top();
}
int main(int argc, char const *argv[])
{
	int n; 
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		cout << setprecision(2) << setiosflags(ios::fixed | ios::showpoint) << calculate(s) << endl;
	}
	return 0;
}