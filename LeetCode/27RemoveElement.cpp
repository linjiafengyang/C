#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end();) {
			if (*iter == val) {
				iter = nums.erase(iter);
			}
			else {
				iter++;
			}
		}
		return nums.size();
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
	int val;
	cin >> val;
	cout << s.removeElement(nums, val) << endl;
	return 0;
}