#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int res = 0;
	int j = 1;
	while (res <= n && a[j] > j) {
		j++;
		res++;
	}
	cout << res;
	return 0;
}