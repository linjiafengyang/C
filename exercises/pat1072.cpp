#include <iostream>
using namespace std;
int main() {
	int n, m;
	int nnum = 0, knum = 0;
	cin >> n >> m;
	int a[10];
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	string name;
	int k, b[15];
	for (int i = 0; i < n; i++) {
		cin >> name >> k;
		bool flag = false;
		for (int j = 0; j < k; j++) {
			cin >> b[j];
			for (int l = 0; l < m; l++) {
				if (b[j] == a[l]) {
					if (!flag) {
						cout << name << ":";
						flag = true;
						nnum++;
					}
					printf(" %04d", b[j]);
					knum++;
				}
			}
		}
		if (flag) cout << endl;
	}
	cout << nnum << " " << knum << endl;
	return 0;
}