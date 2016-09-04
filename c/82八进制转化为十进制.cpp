#include <stdio.h>
int main() {
	int n = 0;
	int i = 0;
	char s[20];
	printf("请输入一个八进制数：\n");
	gets(s);
	while(s[i] != '\0') {
		n = n * 8 + s[i] - '0';
		i++;
	}
	printf("十进制数为：%d\n", n);
	return 0;
}
