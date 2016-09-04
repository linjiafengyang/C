#include <stdio.h>
#include <math.h>
int isprimer(unsigned int n);
int main() {
	unsigned int n, i;
	do {
		printf("请输入一个偶数：\n");
		scanf("%d", &n);
	}while(n % 2 != 0);
	for(i = 1; i < n; i++) {
		if(isprimer(i) && isprimer(n - i)) {
			break;
		}
	}
	printf("偶数%d可以分解为%d和%d两个素数之和\n", n, i, n - i);
}
int isprimer(unsigned int n) {
	int i;
	if(n < 4) {
		return 1;
	}
	else if(n % 2 == 0) {
		return 0;
	}
	else {
		for(i = 3; i < sqrt(n) + 1; i++) {
			if(n % i == 0) {
				return 0;
			}
		}
	}
	return 1;
}
