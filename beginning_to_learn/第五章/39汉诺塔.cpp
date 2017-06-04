#include<stdio.h>
void hanoi(int n, char A, char B, char C);
int main() {
	int n;
	scanf("%d",&n);
	hanoi(n, '1', '2', '3');
	return 0;
}
void hanoi(int n, char A, char B, char C) {
	if(n == 1) {
		printf("%c%c\n", A, C);
	}
	else {
		hanoi(n-1, A, C, B);
		printf("%c%c\n", A, C);
		hanoi(n-1, B, A, C);
	}
}
