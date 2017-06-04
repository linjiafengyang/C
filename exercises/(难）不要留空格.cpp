#include <stdio.h>
int main() {
	int a, b;
	int counter = 0;
	scanf("%d", &a);
	while(counter < a-1) {
		scanf("%d", &b);
		if(b > 0) {
			printf("%d ", b);	
		}
		counter = counter+1;
	}
	while(counter < a) {
		scanf("%d", &b);
		if(b > 0) {
			printf("%d", b);/*不留空格*/ 
		}
		else {
			printf("\b");/*保证了最后一个数肯定不留空格，因为如果最后一个数大于零，由前面不会留空格，若小于零，直接去掉前面正数留下的空格*/ 
		}
		counter = counter+1;
	}
	printf("\n");
	return 0;
}
