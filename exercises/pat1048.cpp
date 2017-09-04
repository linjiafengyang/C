#include <iostream>
using namespace std;
int main() {
	string a, b, c;
	cin >> a >> b;
	int lenA = a.length();
	int lenB = b.length();
	for (int i = 0; i <= lenA / 2 - 1; i++) {
		swap(a[i], a[lenA - 1 - i]);
	}
	for (int i = 0; i <= lenB / 2 - 1; i++) {
		swap(b[i], b[lenB - 1 - i]);
	}
	if (lenA > lenB) {
		b.append(lenA - lenB, '0');
	}
	else {
		a.append(lenB - lenA, '0');
	}
	char str[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
	for (int i = 0; i < a.length(); i++) {
		if (i % 2 == 0) {
			c += str[(a[i] - '0' + b[i] - '0') % 13];
		}
		else {
			int temp = b[i] - a[i];
			if (temp < 0) temp += 10;
			c += str[temp];
		}
	}
	for (int i = c.length() - 1; i >= 0; i--) {
		cout << c[i];
	}
	return 0;
}