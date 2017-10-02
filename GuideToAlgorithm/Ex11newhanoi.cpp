#include <iostream>
using namespace std;
long long f(int* p, int i, int final) {
	if (i == 0) return 0;
	if (p[i] == final) return f(p, i - 1, final);
	return f(p, i - 1, 6 - p[i] - final) + (1LL << (i - 1));
}
const int maxn = 60 + 10;
int n, start[maxn], finish[maxn];
int main() {
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) {
		for (int i = 1; i <= n; i++) cin >> start[i];
		for (int i = 1; i <= n; i++) cin >> finish[i];
		int k = n;
		while (k >= 1 && start[k] == finish[k]) k--;
		long long ans = 0;
		if (k >= 1) {
			int other = 6 - start[k] - finish[k];
			ans = f(start, k - 1, other) + f(finish, k - 1, other) + 1;
		}
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}