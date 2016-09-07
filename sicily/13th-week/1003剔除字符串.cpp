#include <stdio.h>
#include <string.h>
int main() {
	char str1[100], str2[100];
	int i, j;
	int len1, len2;
	scanf("%s%s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i = 0; i < len1; i++) {
		for(j = 0; j < len2; j++) {
			if(str1[i] == str2[j]) {
				str1[i] = ' ';
			}
		}
	}
	for(i = 0; i < len1; i++) {
		if(str1[i] != ' ') {
			printf("%c", str1[i]);
		}
	}
	printf("\n");
	return 0;
}
/*从第一个字符串中删除所有在第二个字符串中出现的字符(包括字母、标点、数字等所有字符)，不能改变其它字符的顺序，区分大小写。 程序中可以假设所有字符串的长度都小于100个字符。

例如：两个字符串分别为"a1b2c3hello123"，"123hello"，把第二个字符串中出现的字符全部剔除之后结果为"abc"。
*/
