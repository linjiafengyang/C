/*
字母重排
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char word[2000][10], sorted[2000][10];
// 字符比较函数
int cmp_char(const void* _a, const void* _b) {
	char* a = (char*)_a;
	char* b = (char*)_b;
	return *a - *b;
}
// 字符串比较函数
int cmp_string(const void* _a, const void* _b) {
	char* a = (char*)_a;
	char* b = (char*)_b;
	return strcmp(a, b);
}
int main() {
	n = 0;
	for (;;) {
		scanf("%s", word[n]);
		if (word[n][0] == '*') break;// 遇到结束标志就终止循环
		n++;
	}
	qsort(word, n, sizeof(word[0]), cmp_string);// 给所有单词排序
	for (int i = 0; i < n; i++) {
		strcpy(sorted[i], word[i]);
		qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp_char);// 给每个单词排序
	}

	char s[10];
	while (scanf("%s", s) == 1) {
		qsort(s, strlen(s), sizeof(char), cmp_char);// 给输入单词排序
		int found = 0;
		for (int i = 0; i < n; i++) {
			if (strcmp(sorted[i], s) == 0) {
				found = 1;
				printf("%s ", word[i]);// 输出原始单词，不是排序后的
			}
		}
		if (!found) printf(":(");
		printf("\n");
	}
	return 0;
}