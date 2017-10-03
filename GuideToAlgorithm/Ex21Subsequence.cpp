/*
有n个正整数组成一个序列。给定整数s，求长度最短的连续序列，使它们的和大于等于S
输出满足条件的最短序列的长度
 */
#include <iostream>
using namespace std;

int main() {
	int n, S;
	cin >> n >> S;
	int A[n];
	for (int i = 1; i <= n; i++) cin >> A[i];
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) sum += A[k];
			if (sum >= S) ans = min(ans, j - i + 1);
		}
	}
	if (ans == n + 1) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}