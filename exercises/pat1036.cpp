#include <iostream>
using namespace std;
int main() {
	int n;
	char c;
	cin >> n >> c;
	int row = (int)(n / 2.0 + 0.5);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == row - 1) {
				cout << c;
			}
			else if (j == 0 || j == n - 1) {
				cout << c;
			}
			else {
				cout << " ";
			}
		}
		if (i != row - 1) {
			cout << endl;
		}
	}
}