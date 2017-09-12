/*
移动小球：不采用链表
 */
#include <iostream>
using namespace std;
int A[500010];
int n, m;
int find(int key) {
	for (int i = 1; i <= n; i++) {
		if (A[i] == key) return i;
	}
}
void shift_circular_left(int l, int r) {
	// p a b c q => a b c p q
	int key = A[l];
	for (int i = l; i < r; i++) {
		A[i] = A[i + 1];
	}
	A[r] = key;
}
void shift_circular_right(int l, int r) {
	// 4 3 2 1 => 1 4 3 2
	int key = A[r];
	for (int i = r; i > l; i--) {
		A[i] = A[i - 1];
	}
	A[l] = key;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) A[i] = i;// 初始化数组
	while (m--) {
		char c[50];
		int x, y;
		scanf("%s%d%d", c, &x, &y);
		int p = find(x), q = find(y);// 查找x和y在数组中的位置
		if (c[0] == 'A') {
			// 1 . . . 4 => . . . 1 4 q > p
			// 4 . . . 1 => 1 4 . . . q < p
			if (q > p) shift_circular_left(p, q - 1);// A[p]到A[q-1]往左循环移动
			else shift_circular_right(q, p);// A[q]到A[p]往右循环移动
		}
		else {
			// 3 . . . 5 => . . . 5 3
			// 5 . . . 3 => 5 3 . . .
			if (q > p) shift_circular_left(p, q);// A[p]到A[q]往左循环移动
			else shift_circular_right(q + 1, p);// A[q+1]到A[p]往右循环移动
		}
	}
	for (int i = 1; i <= n; i++) cout << A[i] << " ";
	cout << endl;
	return 0;
}
