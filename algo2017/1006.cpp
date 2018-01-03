class Solution {
public:
    int longestSubstring(string x, string y) {
        int a = x.length();
        int b = y.length();
        int dp[a + 1][b + 1];
        int max = 0;
        for (int j = 0; j < b; j++) dp[0][j] = 0;
        for (int i = 0; i < a; i++) dp[i][0] = 0;

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                if (x[i-1] == y[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (max < dp[i][j]) max = dp[i][j];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return max;
    }
};
// another solution
class Solution {
private:
    vector<vector<int>> f;
public:
    int longestSubstring(string x, string y) {
        int n, m, i, j;
        n = x.length();
        m = y.length();
        f.resize(n + 1);
        for (i = 0; i <= n; i++) f[i].resize(m + 1);
        int res = 0;
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                if (i == 0 || j == 0 || x[i - 1] != y[j - 1]) f[i][j] = 0;
                else f[i][j] = f[i - 1][j - 1] + 1;
                if (f[i][j] > res) res = f[i][j];
            }
        }
        return res;
    }
};