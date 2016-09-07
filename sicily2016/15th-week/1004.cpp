#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int t;
	cin >> t;
	int a[100];
	char b[100];
	for(int i = 0; i < t; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < 100; i++) {
		b[i] = '*';
	}
	for(int i = 0; i < t; i++) {
		string c(b, a[i]);
		cout << a[i] << ":" << c << endl;
	}
	return 0;
}
