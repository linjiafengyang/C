#include <iostream>
using namespace std;
int main() {
	int T, k;
	cin >> T >> k;
	int n1, b, t, n2;
	for (int i = 0; i < k; i++) {
		cin >> n1 >> b >> t >> n2;
		if (T == 0) {
			cout << "Game Over." << endl;
			break;
		}
		else if (t > T) {
			cout << "Not enough tokens.  Total = " << T << "." << endl;
		}
		else if (b == 0 && n2 < n1) {
			T = T + t;
			cout << "Win " << t << "!  Total = " << T << "." << endl;
		}
		else if (b == 1 && n2 > n1) {
			T = T + t;
			cout << "Win " << t << "!  Total = " << T << "." << endl;
		}
		else if (b == 0 && n2 > n1) {
			T = T - t;
			cout << "Lose " << t << ".  Total = " << T << "." << endl;
		}
		else if (b == 1 && n2 < n1) {
			T = T - t;
			cout << "Lose " << t << ".  Total = " << T << "." << endl;
		}
	}
	return 0;
}