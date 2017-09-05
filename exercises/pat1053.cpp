#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n, d, k, maybe = 0, must = 0;
	double e, temp;
	cin >> n >> e >> d;
	for (int i = 0; i < n; i++) {
		cin >> k;
		int sum = 0;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			if (temp < e) sum++;
		}
		if (sum > (k / 2)) {
			k > d ? must++ : maybe++;
		}
	}
	double maybeResult = (double)maybe / n * 100;
	double mustResult = (double)must / n * 100;
	cout << setiosflags(ios::fixed) << setprecision(1) << maybeResult << "% "
		 << setiosflags(ios::fixed) << setprecision(1) << mustResult << "%";
	return 0;
}