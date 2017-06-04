#include <stdio.h>
int main() {
	int testnum, n, i, j, k, flag;     //注意for循环里面不要用相同的字母 
	int a[101];
	scanf("%d", &testnum);
	for(i = 0;i < testnum;i++) {
		scanf("%d", &n);
		for(j = 0;j < n;j++) {
			scanf("%d", &a[j]);
			if(j == 0) {
				printf("%d", a[0]);   //无论如何先输出第一个数 
			}
			else {
				flag = 0;
				for(k = 0;k < j;k++) { 
					if(a[j] != a[k]) {   //逐一判断，从j==1开始 
						flag = flag + 1;
					}
				}
				if(flag == j) {
					printf(" %d", a[j]);
				}
			}
		}
		printf("\n");
 	}	 
	return 0;
} 
