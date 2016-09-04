#include <stdio.h>
int main() {
	int i;
	for(i = 10; i < 100; i++) {
		if(8 * i < 100 && 9 * i > 99 && 9 * i < 1000) {
			printf("??代表的两位数是：%d\n", i);
			break;
		}
	}
	printf("809*%d == 800*%d+9*%d+1\n", i, i, i);
	return 0;
}
