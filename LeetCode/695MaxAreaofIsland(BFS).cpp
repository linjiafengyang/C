#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();// m:grid的行数; n:grid的列数
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 遍历每一个位置，==1，宽度优先搜索
				if (grid[i][j] == 1) ans = max(ans, bfs(grid, m, n, i, j));
			}
		}
		return ans;
	}
private:
	int bfs(vector<vector<int>>& grid, int m, int n, int row, int col) {
		int area = 1;

		queue<pair<int, int>> q;
		q.push({row, col});// 将已经遍历过的满足条件的结点放进队列

		grid[row][col] = 2;// 标记已经遍历过的满足条件的值
		vector<int> dir({-1, 0, 1, 0, -1});// 搜索的方向：上下左右

		while (!q.empty()) {
			int z = q.front().first, x = q.front().second;// 获取结点的行号、列号
			q.pop();// 删除该结点

			for (int i = 0; i < 4; i++) {
				int r = z + dir[i], c = x + dir[i + 1];
				// 边界判断以及陆地判断
				if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
					grid[r][c] = 2;// 标记已经遍历过的满足条件的值
					area++;
					q.push({r, c});// 将已经遍历过的满足条件的结点放进队列
				}
			}
		}
		return area;
	}
};
int main() {
	Solution s;
	vector<vector<int>> grid = 
	{{0,0,1,0,0,0,0,1,0,0,0,0,0},
 	{0,0,0,0,0,0,0,1,1,1,0,0,0},
 	{0,1,1,0,1,0,0,0,0,0,0,0,0},
 	{0,1,0,0,1,1,0,0,1,0,1,0,0},
 	{0,1,0,0,1,1,0,0,1,1,1,0,0},
 	{0,0,0,0,0,0,0,0,0,0,1,0,0},
 	{0,0,0,0,0,0,0,1,1,1,0,0,0},
 	{0,0,0,0,0,0,0,1,1,0,0,0,0}};

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << s.maxAreaOfIsland(grid) << endl;
	return 0;
}
/*
0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 1 1 0 1 0 0 0 0 0 0 0 0
0 1 0 0 1 1 0 0 1 0 1 0 0
0 1 0 0 1 1 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
 */
