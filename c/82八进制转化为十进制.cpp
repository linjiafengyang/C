#include <stdio.h>
int main() {
	int n = 0;
	int i = 0;
	char s[20];
	printf("������һ���˽�������\n");
	gets(s);
	while(s[i] != '\0') {
		n = n * 8 + s[i] - '0';
		i++;
	}
	printf("ʮ������Ϊ��%d\n", n);
	return 0;
}
