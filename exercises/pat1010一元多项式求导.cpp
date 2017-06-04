#include <iostream>
using namespace std;
int main() {
	int a, b;
	int flag = 0;
	if(cin >> a >> b) {
		flag = 1;
		if(b == 0) {
			cout << "0 0";
			return 0;
		}
		cout << a * b << " " << b - 1;
	}
	while(cin >> a >> b) {
		if(b == 0) {
			return 0;
		}
		cout << " " << a * b << " " << b - 1;
	}
	if(flag == 0) {
		cout << "0 0";
	}
}
