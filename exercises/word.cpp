/*
单词的平均长度
 */
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s;
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		sum += s.length();
	}
	cout << sum / n << endl;
	return 0;
}