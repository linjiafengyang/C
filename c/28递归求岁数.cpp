#include <stdio.h>
int age(int n);
int main() {
	printf("%d\n", age(5));
}
int age(int n) {
	int a;
	if(n == 1) {
		a = 10;
	}
	else {
		a = age(n - 1) + 2;
	}
	return a;
}
/*有5个人坐在一起，问第五个人多少岁？
他说比第4个人大2岁。问第4个人岁数，
他说比第3个人大2岁。问第三个人，又说比
第2人大两岁。问第2个人，说比第一个人大两岁。
最后问第一个人，他说是10岁。请问第五个人多大？*/ 
