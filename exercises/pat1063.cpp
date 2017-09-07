#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	float max = 0.0;
	for (int i = 0; i < n; i++) {
		float a, b, mo;
		cin >> a >> b;
		mo = sqrt(a * a + b * b);
		max = mo > max ? mo : max;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << max;
	return 0;
}