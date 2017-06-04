#include <stdio.h>
int rabbit(int n);
int main() {
	int n;
	scanf("%d", &n);
	while(n != -1) {
		printf("%d\n", rabbit(n));
		scanf("%d", &n);	
	}
	return 0;
}
int rabbit(int n) {
	if(n != -1) {
		if(n == 1 || n == 2) {
			return 2;
		}
		else {
			return rabbit(n - 1) + rabbit(n - 2);
		}		
	}
}//和fibonacci函数相似，只是这个从2 4 6 10 ....开始，分别对应1 2 3 5 8 .... 
