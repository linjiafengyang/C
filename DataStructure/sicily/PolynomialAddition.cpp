#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int m;
	int n;
	int num, expo;
	cin >> m;
	while (m--) {
		std::map<int, int> v1;
		std::map<int, int> v2;
		int max_expo = 0;
		for (int i = 0; i < 2; i++) {
			cin >> n;
			for (int j = 0; j < n; j++) {
				cin >> num >> expo;
				if (max_expo < expo) {
					max_expo = expo;
				}
				if (i == 0) {
					v1[expo] = num;
				}
				if (i == 1) {
					v2[expo] = num;
				}
			}
		}
		std::map<int, int> v3;
		int count = 0;
		for (int i = 0; i <= max_expo; i++) {
			if (v1[i] != 0 || v2[i] != 0) {
				v3[i] = v1[i] + v2[i];
				if (v3[i] != 0) {
					count++;
				}
			}
		}
		cout << count << endl;
		for (int i = max_expo; i >= 0; i--) {
			if (v3[i] != 0) {
				cout << v3[i] << " " << i << endl;
			}
		}
	}
}