#include <iostream>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == b[i]) {
				a[j] = '*';
				b[i] = '*';
			}
		}
	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] != '*') {
			cnt1++;
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] != '*') {
			cnt2++;
		}
	}
	if (cnt2 != 0) {
		cout << "No " << cnt2;
	}
	else {
		cout << "Yes " << cnt1;
	}
	return 0;
}