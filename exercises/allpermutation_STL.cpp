/*
利用STL中的next_permutation函数输出全排列
 */
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n, p[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p + n);// 排序，得到p的最小排列
	do {
		for (int i = 0; i < n; i++) cout << p[i] << " ";// 输出排列p
		cout << endl;
	} while (next_permutation(p, p + n));// 求下一个排列
	return 0;
}