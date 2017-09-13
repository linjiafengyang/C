/*
分金币：圆桌旁坐着n个人，金币总数能被n整除。每个人可以给他左右相邻的人一些金币（注意是圆桌），最终使得每个人的金币数目相等。求出被转手的金币数量的最小值。
3
100
100
100

4
1
2
5
4
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
long long A[1000010], C[1000010], total, M;
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		total = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &A[i]);
			total += A[i];
		}
		M = total / n;
		C[0] = 0;
		for (int i = 1; i < n; i++) {
			C[i] = C[i - 1] + A[i] - M;
		}
		sort(C, C + n);
		long long x1 = C[n / 2], ans = 0;
		for (int i = 0; i < n; i++) {
			ans += abs(x1 - C[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}