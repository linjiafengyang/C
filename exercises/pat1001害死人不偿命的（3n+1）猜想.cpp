#include <stdio.h>
int main() {
	int n;
	int count = 0;
	scanf("%d", &n);
	if(n == 1) {
		printf("%d", count);
	}
	while(n != 1) {
		if(n % 2 == 0) {
			n = n / 2;
			count++;
		}
		else {
			n = (3 * n + 1) / 2;
			count++;
		}
		if(n == 1) {
			printf("%d", count);
		}
	}
}
//�����n���㵽1��Ҫ�Ĳ����� 
