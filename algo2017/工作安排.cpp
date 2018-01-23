#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
bool can[6][6];
bool vis[6];
int dfs(int now) {
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        if (can[now][i] && !vis[i]) {
            vis[i] = true;
            if (now == 0) ans++;
            else ans += dfs(now - 1);
            vis[i] = false;
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    memset(can, 0, sizeof can);
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            can[i][s[j] - '0'] = true;
        }
    }
    cout << dfs(n - 1) << endl;
    return 0;
}