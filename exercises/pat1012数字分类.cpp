#include <stdio.h>
int main() {
	int N, i, j = 1, sum = 0, cnt = 0, flag = 0;
	int n[1001] = {0};
	double A[6] = {0};
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}
	for(i = 0; i < N; i++) {
		switch(n[i] % 5) {
			case 0:
				if(n[i] % 2 == 0) {
					A[1] += n[i];
				}
				break;
			case 1:
				A[2] += j * n[i];
				j *= -1;
				flag++;
				break;
			case 2:
				A[3]++;
				break;
			case 3:
				sum += n[i];
				cnt++;
				break;
			case 4:
				if(n[i] > A[5]) {
					A[5] = n[i];
				}
				break;
		}
	}
	if(cnt != 0) {
		A[4] = sum / (double)cnt;
	}
	for(i = 1; i < 6; i++) {
		if(i == 2) {
			if(flag == 0) {
				printf("N");
			}
			else {
				printf("%d", (int)(A[i]));
			}
		}
		else if(i == 4) {
			if(A[i] == 0) {
				printf("N");
			}
			else {
				printf("%0.1f", A[i]);
			}
		}
		else {
			if(A[i] == 0) {
				printf("N");
			}
			else {
				printf("%d", (int)(A[i]));
			}
		}
		if(i != 5) {
			printf(" ");
		}
	}
}
