#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums;
		for (int i = 0; i < nums1.size(); i++) {
			nums.push_back(nums1[i]);
		}
		for (int i = 0; i < nums2.size(); i++) {
			nums.push_back(nums2[i]);
		}
		sort(nums.begin(), nums.end());
		int len = nums.size();
		double res;
		if (len % 2 == 0) {
			res = double(nums[len / 2 - 1] + nums[len / 2]) / 2;
		}
		else {
			res = double(nums[len / 2]);
		}
		return res;
	}
};
int main() {
	int n1, n2;
	cin >> n1 >> n2;
	vector<int> nums1, nums2;
	for (int i = 0; i < n1; i++) {
		 int t;
		 cin >> t;
		 nums1.push_back(t);
	}
	for (int i = 0; i < n2; i++) {
		int t;
		cin >> t;
		nums2.push_back(t);
	}
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}