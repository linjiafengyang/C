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
//编写程序判断输入的字符串是否回文 
//abcba
//yes 
//accba
//no c (从左到右，第一个不满足回文条件的字符).
