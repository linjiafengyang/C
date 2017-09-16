#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		/*
		int len = prices.size();
		if (!len) return 0;
		vector<int> sub(len);
		sub[0] = prices[0];
		// 求相邻之间的差值变化
		for (int i = 1; i < len; i++) {
			sub[i] = prices[i] - prices[i - 1];
		}
		int maxCur = 0, maxSoFar = 0;
		for (int i = 1; i < len; i++) {
			maxCur += sub[i];
			maxCur = max(0, maxCur);
			maxSoFar = max(maxCur, maxSoFar);
		}
		*/
		int maxCur = 0, maxSoFar = 0;
		for (int i = 1; i < prices.size(); i++) {
			maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
			maxSoFar = max(maxCur, maxSoFar);
		}
		return maxSoFar;
	}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << s.maxProfit(nums) << endl;
	return 0;
}