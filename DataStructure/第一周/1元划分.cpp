#include <iostream>

using namespace std;

int main() {
	int count = 0;
	int cnt = 0;
	for (int i5 = 0; i5 <= 20; i5++) {
		for (int i2 = 0; i2 <= (100 - i5 * 5) / 2; i2++) {
			cout << i5 << '*' << 5 << '+' << i2 << '*' << 2 << '+' << (100 - 5 * i5 - 2 * i2) / 5 << '*' << 1 << '=' << 100 << endl;
			count++;
			cnt++; 
		}
	}
	cout << count << endl;
	cout << cnt << endl;
}
