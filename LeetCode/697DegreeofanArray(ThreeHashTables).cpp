/*
input:
1 2 2 3 1 4 2
output:
6
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		unordered_map<int, int> hash;// 哈希表记录每个数字出现的次数
		unordered_map<int, int> hash_left;// 哈希表维护每个数组出现的最左位置
		unordered_map<int, int> hash_right;// 哈希表维护每个数组出现的最右位置

		int maxFreq = 0;
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]]++;
			maxFreq = max(hash[nums[i]], maxFreq);// 找出最高频率

			if (hash_left.find(nums[i]) == hash_left.end()) {// 为真，即表示该数字还没出现
				hash_left[nums[i]] = i;
			}
			hash_right[nums[i]] = i;
		}
		if (maxFreq == 1) return 1;

		int maxLen = nums.size();
		for (auto m : hash) {
			if (m.second == maxFreq) {
				maxLen = min(maxLen, hash_right[m.first] - hash_left[m.first] + 1);
			}
		}

		// int maxLen = nums.size();// 最大长度结果
		// for (int i = 0; i < maxFreqNum.size(); i++) {
		// 	int minIndex = -1;// 找出最高频率数字在数组中最左边的下标
		// 	int maxIndex = -1;// 找出最高频率数字在数组中最右边的下标
		// 	int freq = maxFreq;
		// 	for (int j = 0; j < nums.size() && freq > 0; j++) {
		// 		if (nums[j] == maxFreqNum[i]) {
		// 			freq--;
		// 			if (minIndex == -1) minIndex = j;// minIndex等于-1时，即为最左边位置
		// 			if (freq == 0) maxIndex = j;// freq等于0时，即为最右边位置
		// 		}
		// 	}
		// 	// 更新最大长度结果
		// 	if (maxIndex - minIndex + 1 < maxLen) {
		// 		maxLen = maxIndex - minIndex + 1;
		// 	}
		// }
		
		return maxLen;
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
	cout << s.findShortestSubArray(nums) << endl;
	return 0;
}