#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int next(int n, int k) {
	stringstream ss;
	ss << (long long)k * k;// 注意，k*k可能会溢出，必须先转化为long long再相乘
	string s = ss.str();
	if (s.length() > n) s = s.substr(0, n);// 取前n位
	int ans;
	stringstream ss2(s);
	ss2 >> ans;
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