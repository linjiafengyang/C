/*
小球下落（二叉树）
 */
#include <stdio.h>
#include <string.h>
const int MAXD = 20;
int s[1 << MAXD];// 最大结点个数为2^MAXD-1
int main() {
	int D, I;
	while (scanf("%d%d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));// 开关
		int k, n = (1 << D) - 1;// n是最大结点编号2^D-1
		for (int i = 0; i < I; i++) {
			k = 1;
			for (;;) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;// 根据开关状态选择下落方向
				if (k > n) break;// 小球已经出界
			}
		}
		printf("%d\n", k / 2);// 出界前的叶子结点编号
	}
	return 0;
}