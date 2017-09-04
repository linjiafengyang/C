#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[100000], b[100000], c[100000];
int main() {
	int n;
	int max = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i] && b[i] > max) {
			c[cnt++] = b[i];
		}
		if (b[i] > max) {
			max = b[i];
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		if (i != 0) cout << " ";
		cout << c[i];
	}
	cout << endl;
	return 0;
}