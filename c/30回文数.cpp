#include <stdio.h>
int main() {
	long ge, shi, qian, wan, x;
	printf("请输入一个五位数：");
	scanf("%ld", &x);
	wan = x / 10000;
	qian = x % 10000 / 1000;
	shi = x % 100 / 10;
	ge = x % 10;
	if(ge == wan && shi == qian) {
		printf("这是一个回文数。");
	}
	else {
		printf("这不是回文数。");
	}
}
