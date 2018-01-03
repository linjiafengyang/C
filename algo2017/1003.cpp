class Solution {
public:
    vector<vector<int>> nearestZero(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    for (int k = 0; k < rows; k++)
                        for (int l = 0; l < cols; l++)
                            if (matrix[k][l] == 0) {
                                // abs(k - i) + abs(l - j): distance from 0 to 1
                                dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
                            }
                }
            }
        }
        return dist;
    }
};
// another solution
class Solution {
public:
    vector<vector<int>> nearestZero(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        queue<pair<int, int>> Q;
        const int D[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int n, m, row, col, i, j;
        pair<int, int> u;
        n = matrix.size();
        m = matrix[0].size();
        ans.resize(n);
        for (i = 0; i < n; i++) ans[i].resize(m);

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    Q.push(make_pair(i, j));
                    ans[i][j] = 0;
                }
                else {
                    ans[i][j] = -1;
                }
            }
        }
        while (!Q.empty()) {
            u = Q.front();
            Q.pop();
            for (i = 0; i < 4; i++) {
                row = u.first + D[i][0];
                col = u.second + D[i][1];
                if (row >= 0 && row < n && col >= 0 && col < m && ans[row][col] == -1) {
                    ans[row][col] = ans[u.first][u.second] + 1;
                    Q.push(make_pair(row, col));
                }
            }
        }
        return ans;
    }
};