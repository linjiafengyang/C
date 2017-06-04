#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int i, n;
	bool notFirst = false;
	while (cin >> n) {
		int *a = new int[n + 1];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		a[n] = 0;//末尾加个0
		if (notFirst) {
			cout << endl;
		}
		notFirst = true;
		int cnt = 1;
		for (i = 1; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				cout << a[i - 1] << " " << cnt << endl;
				cnt = 1;
			}
			else {
				cnt++;
			}
		}
		delete []a;
	}
	return 0;
}