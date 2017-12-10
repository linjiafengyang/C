#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int> top3;
		for (int num : nums) {
			top3.insert(num);
			if (top3.size() > 3)
				top3.erase(top3.begin());
		}
		return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
	}
};
int main() {
	Solution s;
	vector<int> nums;
	int n, num;
	cin >> n;
	while (n-- > 0) {
		cin >> num;
		nums.push_back(num);
	}
	cout << s.thirdMax(nums) << endl;
	return 0;
}