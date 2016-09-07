#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin >> t;
	double a[100];
	for(int i = 0; i < t; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < t; i++) {
		cout << a[i] << endl;
		cout << setprecision(6) << fixed << showpoint << a[i] << endl;
		cout << resetiosflags(ios::fixed | ios::showpoint);
	}
	return 0;
}
