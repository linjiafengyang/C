#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		// 数组大小==k或者==1，rotate之后还是原来的数组
		if (nums.size() == k || nums.size() == 1) return;
		// 若k大于数组大小，前若干倍nums.size()个rotate都没改变原数组
		// 此时只需要k%nums.size()步rotate即可
		if (k > nums.size()) {
			k = k % nums.size();
		}
		// 先把需要放到前面的数放到一个新数组中去
		vector<int> temp;
		for (int i = nums.size() - 1; i >= nums.size() - k; i--) {
			temp.push_back(nums[i]);
		}
		// 然后把需要放到后面的数放到原数组的后面去
		for (int i = nums.size() - k - 1; i >= 0; i--) {
			nums[i + k] = nums[i];
		}
		// 把新数组中的数放回原数组中
		int tempSize = k - 1;
		for (int i = 0; i < k; i++) {
			nums[i] = temp[tempSize--];
		}
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
	s.rotate(nums, k);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}