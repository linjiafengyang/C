#include <iostream>
using namespace std;
int main() {
	int n, temp;
	int max, min;
	int i, j;
	int a[4];
	cin >> n;
	do {
		max = 0;
		min = 0;
		for(i = 0; i < 4; i++) {
			a[i] = n % 10;
			n = n / 10;
		}
		for(i = 1; i < 4; i++) {
			for(j = 0; j < 4 - i; j++) {
				if(a[j] > a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		for(i = 0; i < 4; i++) {
			min = min * 10 + a[i];
		}
		for(j = 3; j >= 0; j--) {
			max = max * 10 + a[j];
		}
		n = max - min;
		printf("%.4d - %.4d = %.4d\n", max, min, n);
	} while(n != 6174 && n != 0);
}
