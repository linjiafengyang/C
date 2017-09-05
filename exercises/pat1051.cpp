#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
	double r1, p1, r2, p2;
	cin >> r1 >> p1 >> r2 >> p2;
	double A, B;
	A = r1 * r2 * cos(p1) * cos(p2) - r1 * r2 * sin(p1) * sin(p2);
	B = r1 * r2 * sin(p1) * cos(p2) + r1 * r2 * cos(p1) * sin(p2);
	if (A < 0 && A + 0.005 >= 0) {
		cout << "0.00";
	}
	else {
		cout << setiosflags(ios::fixed) << setprecision(2) << A;
	}
	if (B >= 0) {
		cout << "+" << setiosflags(ios::fixed) << setprecision(2) << B << "i";
	}
	else if (B < 0 && B + 0.0005 >= 0) {
		cout << "+0.00i";
	}
	else {
		cout << setiosflags(ios::fixed) << setprecision(2) << B << "i";
	}
	return 0;
}