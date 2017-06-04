#include <stdio.h>
int main() {
	int n, i, j, temp;      //n 表示杨辉三角的size 
	scanf("%d", &n);
	printf("1\t\n");  //先输出第一行的数，因为必为1 
	for(i = 2;i <= n;i++) {         //从第二行开始 
		printf("1\t");             //第一个数都为一 
		temp = 1;
		for(j = 1;j <= i - 2;j++) {      //判断中间列，除去第一列和最后一列，每一行有 i-1 列 
			temp = (i - j) * temp / j;
			printf("%d\t",temp);
		}
		printf("1\t\n");            //最后一列也都为一 
	}
	return 0;
}
//或者：  输出的部分是一个下三角形，对角线和第0列的元素都是1，从第2行开始，其它元素的值是其相邻上一行元素及上一行前一列元素之和，即a[i][j]=a[i-1][j-1]+a[i-1][j] 
