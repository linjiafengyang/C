#include <iostream>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int score[m], answer[m];
	for (int i = 0; i < m; i++) {
		cin >> score[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> answer[i];
	}
	for (int i = 0; i < n; i++) {
		int total = 0;
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			if (temp == answer[j]) {
				total += score[j];
			}
		}
		cout << total << endl;
	}
	return 0;
}