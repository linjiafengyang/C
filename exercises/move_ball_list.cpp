/*
移动小球
6 2
A 1 4
B 3 5
输出：2 1 4 5 3 6
 */
#include <iostream>
#include <cstdio>
using namespace std;
int Left[500010], Right[500010], n, t;
// a的右边是b，b的左边是a
void link(int a, int b) {
	Right[a] = b;
	Left[b] = a;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		Left[i] = i - 1;
		Right[i] = i + 1;
	}
	Right[n] = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int x, y;
		char c;
		c = getchar();
		while (c != 'A' && c != 'B') c = getchar();
		cin >> x >> y;
		link(Left[x], Right[x]);
		if (c == 'B') {
			// x .. y => .. y x Right[Y]
			link(x, Right[y]);
			link(y, x);
		}
		else {
			// x .. y => .. x y
			link(Left[y], x);
			link(x, y);
		}
	}
	int head;
	for (head = 1; head <= n && Left[head] != 0; head++);
	cout << head << " ";
	while (Right[head] != 0) {
		head = Right[head];
		cout << head << " ";
	}
	cout << endl;
	return 0;
}