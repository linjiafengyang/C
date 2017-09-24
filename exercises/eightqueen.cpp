#include <iostream>
using namespace std;
int n, tot = 0;
int vis[2][10000] = {0};
int C[10000];
void search(int cur) {
	int i, j;
	if (cur == n) tot++;// 递归边界，只要走到了这里，所有皇后必然不冲突
	else {
		for (i = 0; i < n; i++) {
			int ok = 1;
			C[cur] = i;// 尝试把第cur行的皇后放在第i列
			for (j = 0; j < cur; j++) {// 检查是否和前面的皇后冲突
				if (C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j]) {
					ok = 0;
					break;
				}
			}
			if (ok) search(cur + 1);// 如果合法，这继续递归
		}
	}
}
/*void search(int cur) {
	int i, j;
	if (cur == n) tot++;// 递归边界，只要走到了这里，所有皇后必然不冲突
	else {
		for (i = 0; i < n; i++) {
			if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) {// 利用二维数组直接判断
				C[cur] = i;// 如果不用打印解，整个C数组可以省略
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;// 修改全局变量
				search(cur + 1);
				vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;// 切记一定要改回来
			}
		}
	}
}*/
int main() {
	cin >> n;
	search(0);
	cout << tot << endl;
	return 0;
}
// 例如输入4，表示4个皇后，则输出结果为2，(1,3,0,2)(2,0,3,1)满足