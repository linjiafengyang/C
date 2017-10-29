/*
Given a non-empty 2D array grid of 0's and 1's, 
an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. 
(If there is no island, the maximum area is 0.)

Example 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, 
because the island must be connected 4-directionally.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();// m:grid的行数; n:grid的列数
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 遍历每一个位置，==1，深度优先搜索
				if (grid[i][j] == 1) ans = max(ans, dfs(grid, m, n, i, j));
			}
		}
		return ans;
	}
private:
	int dfs(vector<vector<int>>& grid, int m, int n, int row, int col) {
		int area = 1;
		grid[row][col] = 2;// 标记已经遍历过的满足条件的值
		vector<int> dir({-1, 0, 1, 0, -1});// 搜索的方向：上下左右
		for (int i = 0; i < 4; i++) {
			int r = row + dir[i], c = col + dir[i + 1];
			// 边界判断以及陆地判断
			// 若为真，继续深搜
			if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1){
				area += dfs(grid, m, n, r, c);
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
