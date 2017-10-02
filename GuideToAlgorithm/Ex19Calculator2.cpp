#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int buf[100];
int next(int n, int k) {
	if (!k) return 0;
	long long k2 = (long long)k * k;
	int L = 0;
	while (k2 > 0) {// 分离并保存k^2的各个数字
		buf[L++] = k2 % 10;
		k2 /= 10;
	}
	if (n > L) n = L;
	int ans = 0;
	for (int i = 0; i < n; i++) {// 把前min{n,L}位重新组合
		ans = ans * 10 + buf[--L];
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		set<int> s;
		int ans = k;
		while (!s.count(k)) {// 以前没出现过
			s.insert(k);
			if (k > ans) ans = k;
			k = next(n, k);
		}
		cout << ans << endl;
	}
	return 0;
}