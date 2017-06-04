#include <stdio.h>
int main() {
	int n, i, j;
	int a[100];
	int counter = 0;
	scanf("%d", &n);
	for(i = 0;i < n;i++) {
		scanf("%d", &a[i]);  //输入 n 个数 
	}
	for(i = 0;i < n;i++) {
		for(j = i;j < n;j++) {
			if(a[i] == 2 * a[j + 1] || a[j + 1] == 2 * a[i]) {     //逐一判断，从 a[0] 和 a[1] 开始 
				counter++;
			}
		}
	}
	printf("%d\n", counter);
	return 0;
}
