#include <stdio.h>
#include <algorithm>
int main(int argc, char const *argv[])
{
	int N;
	long long int p, a[100010];
	int count = 0;
	scanf("%d%lld", &N, &p);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	std::sort(a, a + N);
	for (int i = 0; i < N; i++) {//遍历，将a[i]作为最小数
		for (int j = i + count; j < N; j++) {//j置为要满足可以更新数列长度的值，减少循环次数
			if (a[j] > a[i] * p) break;//如果不满足条件了，则将下一个元素作为最小值
			if (j - i + 1 > count) count = j - i + 1;//如果此次的长度大于上一次，更新数列长度
		}
	}
	printf("%d", count);
	return 0;
}
