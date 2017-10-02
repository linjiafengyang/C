/*
计数排序
 */
#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n, x, c[101];
	while (scanf("%d", &n) == 1 && n) {
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			c[x]++;
		}
		int first = 1;// 标志first=1表示还没输出过整数
		for (int i = 1; i <= 100; i++) {
			for (int j = 0; j < c[i]; j++) {
				if (!first) printf(" ");// 从第二个数开始，每输出一个数之前先输出一个空格
				first = 0;
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}