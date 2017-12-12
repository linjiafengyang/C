#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		set<int> s;
		int currentSize = 0;// 记录当前集合s的大小
		for (int i = 0; i < nums.size(); i++) {
			s.insert(nums[i]);
			// 若相等，表示insert了一个已经出现过的数，即找到重复的数
			// 内循环遍历得到之前出现的数，两者相减后再与k比较，得出结果
			if (s.size() == currentSize) {
				for (int j = i - 1; j >= 0 && i - j <= k; j--) {
					if (nums[i] == nums[j]) return true;
				}
			}
			currentSize = s.size();
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<int> nums;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		nums.push_back(t);
	}
	int k;
	cin >> k;
	cout << s.containsNearbyDuplicate(nums, k) << endl;
	return 0;
}