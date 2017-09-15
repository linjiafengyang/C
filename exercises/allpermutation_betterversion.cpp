/*
生成1~n的全排列
 */
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
int vis[50];
void print_permutation(int n, int A[], int cur) {
	if (cur == n) {
		for (int i = 0; i < n; i++) cout << A[i] << " ";
		putchar('\n');
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				A[cur] = i;
				print_permutation(n, A, cur + 1);
				vis[i] = 0;
			}
		}
	}
}
int main() {
	memset(vis, 0, sizeof(vis));
	int n, A[50];
	cin >> n;
	print_permutation(n, A, 0);
	printf("n=%d,time used: %.2lf\n",n, (double)clock()/CLOCKS_PER_SEC);
	return 0;
}