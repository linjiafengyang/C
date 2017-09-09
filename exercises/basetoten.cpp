/*
n进制转十进制
 */
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int b;
	cin >> b;
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += pow(b, s.length() - 1 - i) * (s[i] - '0');
	}
	cout << sum;
	return 0;
}