/*
小球下落
 */
#include <stdio.h>
#include <string.h>
const int MAXD = 20;
int s[1 << MAXD];// 最大结点个数为2^MAXD-1
int main() {
	int D, I;
	while (scanf("%d%d", &D, &I) == 2) {
		int k = 1;
		for (int i = 0; i < D - 1; i++) {
			if (I % 2) { // 当I是偶数时，它是往右走的第I/2个小球
				k = k * 2;
				I = (I + 1) / 2;
			}
			else { // 当I是奇数时，它是往左走的第I+1 / 2个小球
				k = k * 2 + 1;
				I /= 2;
			}
		}
		printf("%d\n", k);// 叶子结点编号
	}
	return 0;
}