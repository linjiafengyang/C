#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, lengthi;
    int sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> lengthi;
        v.push_back(lengthi);
        sum += v[i];
    }
    vector<int> dp(sum / 2 + 1);// 存储任务耗时，容量最大为sum/2
    for (int i = 0; i < n; i++) {
        for (int j = sum / 2; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);// dp[j]表示容量为j时存储的最大任务耗时
            // 一个cpu看做一个背包，容量为sum/2
        }
    }
    cout << max(dp[sum / 2], sum - dp[sum / 2]) << endl;
    return 0;
}