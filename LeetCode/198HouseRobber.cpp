#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int rob = 0;// max money can get if rob current house
		int notrob = 0;// max money can get if not rob current house
		for (int i = 0; i < nums.size(); i++) {
			int currob = notrob + nums[i];// if rob current value, previous house must not be robbed
			notrob = max(notrob, rob);// if not rob ith house, take the max value of robbed (i-1)th house and not rob (i-1)th house
			rob = currob;
		}
		return max(rob, notrob);
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}
/*
input:
5
2 5 4 3 1

output:
8
 */