#include <cstdio>
#include <algorithm>
using namespace std;
int A[100000], n;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &A[i]);
		int ans = A[0] - A[1];// 初始值。注意不要初始化为0，因为最终答案可能小于0
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, A[i] - A[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}