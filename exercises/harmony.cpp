/*
调和级数1+1/2+1/3...
 */
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n;
	cin >> n;
	double f = 0.0;
	for (int i = 1; i <= n; i++) {
		f += (double)1 / i;
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << f;
	return 0;
}