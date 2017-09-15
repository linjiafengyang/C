/*
双基回文数：一个正整数至少在两个不同的进制（2~9）下都是回文数，则称为双基回文数。
输入一个正整数n，找出比它大的最小双基回文数
输入
1600000
输出
1632995
 */
#include <iostream>
using namespace std;
bool ok(int n) {
	int s[30];
	int cnt = 0, base = 10;// cnt来计算找到的个数，等于2时返回true
	bool flag;
	do {
		int l = -1, t = n;
		do {
			s[++l] = t % base;
			t /= base;
		} while (t);
		flag = true;
		for (int i = 0; i <= l; i++) {
			if (s[i] != s[l - i]) {
				flag = false;
				break;
			}
		}
		if (flag) cnt++;
		base--;
	} while (base >= 2 && cnt < 2);
	if (cnt == 2) return true;
	return false;
}
int main() {
	int n, i;
	cin >> n;
	for (i = n + 1; !ok(i); i++);
	cout << i << endl;
	return 0;
}