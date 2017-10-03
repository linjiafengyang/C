/*
最大子矩阵：给定一个m*n的矩阵，其中一些格子是空地（F），其他是障碍（R）。找出一个全部由F组成的面积最大的子矩阵，输出其面积乘以3后的结果
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000;
int mat[maxn][maxn], up[maxn][maxn], left[maxn][maxn], right[maxn][maxn];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int m, n;
		// 读入数据
		scanf("%d%d", &m, &n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				char ch = getchar();
				while (ch != 'F' && ch != 'R') ch = getchar();
				mat[i][j] = ch == 'F' ? 0 : 1;
			}
		}

		int ans = 0;
		// 从上到下逐行处理
		for (int i = 0; i < m; i++) {
			int lo = -1, ro = n;
			// 从左到右扫描，维护up和left
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					up[i][j] = left[i][j] = 0;
					lo = j;
				}
				else {
					up[i][j] = i == 0 ? 1 : up[i - 1][j] + 1;
					left[i][j] = i == 0 ? lo + 1 : max(left[i - 1][j], lo + 1);
				}
			}
			// 从右到左扫描，维护right并更新答案
			for (int j = n - 1; j >= 0; j--) {
				if (mat[i][j] == 1) {
					right[i][j] = n;
					ro = j;
				}
				else {
					right[i][j] = i == 0 ? ro - 1 : min(right[i - 1][j], ro - 1);
					ans = max(ans, up[i][j] * (right[i][j] - left[i][j] + 1));
				}
			}
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}