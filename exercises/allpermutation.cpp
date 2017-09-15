/*
生成1~n的全排列
 */
#include <iostream>
#include <ctime>
using namespace std;
void print_permutation(int n, int* A, int cur) {
	if (cur == n) { // 递归边界
		for (int i = 0; i < n; i++) cout << A[i] << " ";
		putchar('\n');
	}
	else {
		for (int i = 1; i <= n; i++) { // 尝试在A[cur]中填各种整数i
			int ok = 1;
			for (int j = 0; j < cur; j++) {
				if (A[j] == i) {// 如果i已经在A[0]~A[cur-1]出现过，则不能再选
					ok = 0;
					break;
				}
			}
			if (ok) {
				A[cur] = i;
				print_permutation(n, A, cur + 1);// 递归调用
			}
		}
	}
}
int main() {
	int n, A[50];
	cin >> n;
	print_permutation(n, A, 0);
	printf("n=%d,time used: %.2lf\n",n, (double)clock()/CLOCKS_PER_SEC);
	return 0;
}