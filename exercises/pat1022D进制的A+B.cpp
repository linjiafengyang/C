#include <iostream>

using namespace std;

int main() {
	int a, b, d;
	cin >> a >> b >> d;
	int sum;
	sum = a + b;
	int s[100];
	int i = 0;
	while (sum != 0) {
		s[i++] = sum % d;
		sum = sum / d;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << s[j];
	}
	if (i == 0) cout << "0";
	return 0;
}