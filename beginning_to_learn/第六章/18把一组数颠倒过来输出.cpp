#include <stdio.h>
#define SIZE 10
void reverse(const int b[], int startIndex, int size);
int main() {
	int a[SIZE] = {8, 3, 5, 1, 4, 2, 7, 0, 9, 6};
	reverse(a, 0, SIZE);
}
void reverse(const int b[], int startIndex, int size) {
	if(startIndex < size) {
		reverse(b, startIndex + 1, size);
		printf("%d ", b[startIndex]);
	}
}
