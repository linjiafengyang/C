/*
有n个正整数组成一个序列。给定整数s，求长度最短的连续序列，使它们的和大于等于S
输出满足条件的最短序列的长度
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, S;
	cin >> n >> S;
	int A[n];
	for (int i = 1; i <= n; i++) cin >> A[i];

	int B[n];
	B[0] = 0;
	for (int i = 1; i <= n; i++) B[i] = B[i - 1] + A[i];
	for (int i = 1; i <= n; i++) cout << B[i] << " ";
	cout << endl;

	int ans = n + 1;
	int i = 1;
	for (int j = 1; j <= n; j++) {
		if (B[i - 1] > B[j] - S) continue;// 没有满足条件的i，换下一个j
		while (B[i] <= B[j] - S) i++;
		ans = min(ans, j - i + 1);
	}
	if (ans == n + 1) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}