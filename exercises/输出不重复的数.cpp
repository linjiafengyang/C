#include <stdio.h>
int main() {
	int testnum, n, i, j, k, flag;     //ע��forѭ�����治Ҫ����ͬ����ĸ 
	int a[101];
	scanf("%d", &testnum);
	for(i = 0;i < testnum;i++) {
		scanf("%d", &n);
		for(j = 0;j < n;j++) {
			scanf("%d", &a[j]);
			if(j == 0) {
				printf("%d", a[0]);   //��������������һ���� 
			}
			else {
				flag = 0;
				for(k = 0;k < j;k++) { 
					if(a[j] != a[k]) {   //��һ�жϣ���j==1��ʼ 
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
