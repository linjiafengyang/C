#include <stdio.h>
int main() {
	char s[100];
	scanf("%s", s);
	int i;
	int count = 0;
	for(i = 0; s[i] != '\0'; i++) {
		count++;
	}
	int temp = 1;
	for(i = count - 1; i >= 0; i--) {
		if(s[i] != s[count - 1 - i]) {
			temp = 0;
			break;
		}
	}
	if(temp) {
		printf("yes");
	}
	else {
		printf("no %c", s[count - 1 - i]);
	}
}
//��д�����ж�������ַ����Ƿ���� 
//abcba
//yes 
//accba
//no c (�����ң���һ������������������ַ�).
