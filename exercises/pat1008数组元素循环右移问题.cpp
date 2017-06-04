#include <stdio.h>
int main() {
	int A[1000] = {0};
	int N, M;
	scanf("%d%d", &N, &M);
	M %= N;
	for(int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		A[N + i] = A[i];
	}
	for(int i = 0; i < N; i++) {
		A[i] = A[N - M + i];
	}
	for(int i = 0; i < N; i++) {
		printf("%d", A[i]);
		if(i != N - 1) {
			printf(" ");
		}
	}
}
