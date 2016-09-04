#include <stdio.h>
#include <string.h>
void swap(char* str1, char* str2);
int main() {
	char str1[20], str2[20], str3[20];
	printf("请输入三个字符串：\n");
	gets(str1);
	gets(str2);
	gets(str3);
	if(strcmp(str1, str2) > 0) {
		swap(str1, str2);
	}
	if(strcmp(str2, str3) > 0) {
		swap(str2, str3);
	}
	if(strcmp(str1, str2) > 0) {
		swap(str1, str2);
	}
	printf("排序后的结果是：\n");
	printf("%s\n%s\n%s\n", str1, str2, str3);
	return 0;
}
void swap(char* str1, char* str2) {
	char temp[20];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}
