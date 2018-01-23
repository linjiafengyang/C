#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string s[52];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    int maxCnt = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (s[j][i] == s[j - 1][i]) {
                cnt++;
            }
            else {
                maxCnt = max(maxCnt, cnt);
                cnt = 1;
            }
        }
        maxCnt = max(maxCnt, cnt);
    }
    cout << maxCnt << endl;
    return 0;
}