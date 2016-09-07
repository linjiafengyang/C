#include <iostream>
using namespace std;
template<typename T>
T max(T seq[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = n - 1; j >= i + 1; j--) {
			if(seq[j] < seq[j - 1]) {
				T temp;
				temp = seq[j];
				seq[j] = seq[j - 1];
				seq[j - 1] = temp;
			}
		}
	}
	return seq[n - 1];
}
int main(int argc, char** argv) {
	int seq[5] = {5, 3, 4, 1, 2};
	cout << max(seq, 5);
	return 0;
}
