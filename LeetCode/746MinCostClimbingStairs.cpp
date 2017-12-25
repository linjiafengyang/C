#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n);
		dp[0] = cost[0];
		dp[1] = cost[1];
		for (int i = 2; i < n; i++) {
			dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
		}
		return min(dp[n - 2], dp[n - 1]);
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> cost(n);
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}
	Solution s;
	cout << s.minCostClimbingStairs(cost) << endl;
	return 0;
}