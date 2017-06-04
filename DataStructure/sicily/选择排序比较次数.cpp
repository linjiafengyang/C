#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	int a[1010] = {0};
	/*
	for (int i = 0; i < N; i++) 
		cin >> a[i];

	int min;
	int count = 0;
	for (int i = 0; i < N - 1; i++) {
		min = i;
		for (int j = i + 1; j < N; i++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	*/
	while (cin >> N) {
		for (int i = 0; i < N; i++) cin >> a[i];
		cout << N * (N - 1) / 2 << endl;
	}
	return 0;
}
