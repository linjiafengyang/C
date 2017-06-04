#include <stdio.h>
int main() {
	int num[50];
	int i, j, k, m, n;
	int *p;
	scanf("%d", &n);//输入总人数
	p = num;
	for(i = 0; i < n; i++) {
		*(p + i) = i + 1;//以1至n为序，给每个人编号
	}
	i = 0;//i为每次循环时计数变量
	k = 0;//k为按1 2 3报数时的计数变量
	m = 0;//m为退出人数
//当退出人数比n-1少时（即未退出人数大于1时）执行循环体 
	while(m < n - 1) {
		if(*(p + i) != 0) {
			k++;
		}
		if(k == 3) {//将退出人的编号置为0
			*(p + i) = 0;
			k = 0;
			m++;
		}
		i++;
		if(i == n) {//报数到尾后i恢复为0 
			i = 0;
		}
	}
	while(*p == 0) {
		p++;
	}
	printf("%d", *p);
	return 0;
}
