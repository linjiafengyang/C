#include <iostream>

using namespace std;

int main() {
	int a[10];
	int n, i, j;
	for (i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (i = 1; i < 10; i++) {
		if (a[i] > 0) {
			cout << i;
			a[i]--;
			break;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < a[i]; j++) {
			cout << i;
		}
	}
}