#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int size = nums.size();
		sort(nums.begin(), nums.end());
		bool flag = true;
		int temp = 0, cnt = 0;
		for (int i = size - 1; i > 0; i--) {
			if (nums[i] != nums[i - 1]) {
				temp = i - 1;// 记录下当前循环到达的位置
				cnt++;
				if (cnt == 2) {// 表示从大到小已有两个数不相等，即找到第三大的数
					flag = false;
					break;
				}
			}
		}
		if (flag) {// 表示未找到第三大的数，因此返回最大的数
			return nums[size - 1];
		}
		else {
			return nums[temp];
		}
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