#include <iostream>
using namespace std;
template<typename T>
int find_lower_bound(T seq[], int n, const T& value) {
	int t = -1;
	for(int i = 0; i < n; i++) {
		if(seq[i] < value) {
			t = i;
			break;
		}
	}
	if(t == -1) {
		return -1;
	}
	for(int i = 0; i < n; i++) {
		if(seq[t] < seq[i] && seq[i] < value) {
			t = i;
		}
	}
	return t;
}
int main(int argc, char** argv) {
	int seq[5] = {2,1,3,4,3};
	cout << find_lower_bound(seq, 5, 4);
	return 0;
}
