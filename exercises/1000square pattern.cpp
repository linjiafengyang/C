#include <stdio.h>
int main() {
	int n, i, j;
	scanf("%d", &n);
	for(i = 0;i < n / 2 + 1;i++) {   //循环前面的 n / 2 + 1 
		for(j = 0;j < i;j++) {       //打印 i 个 “- ” 
			printf("-"); 
		}
		for(j = 0;j < n - 2 * i;j++) {        //n - 2 * i 表示打印的个数逐渐减二个 
			printf("+");
		}
		for(j = 0;j < i;j++) {           //打印 i 个 “- ” 
			printf("-");
		}
		printf("\n");
	}
	for(i = 0;i < n / 2;i++) {		   // 循环后面的 n / 2 个 
		for(j = 0;j < n / 2 - i - 1;j++) {      //打印的 “- ”逐渐减少 
			printf("-");
		}
		for(j = 0;j < 2 * i + 3;j++) {           //i = 0时打印 3 个；i = 1时打印 5 个；依次递增  
			printf("+");
		}
		for(j = 0;j < n / 2 - i - 1;j++) {
			printf("-");
		} 
		printf("\n");
	}
	return 0;
}
	
