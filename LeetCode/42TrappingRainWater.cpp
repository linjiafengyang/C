#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		int size = height.size();
		for (int i = 1; i < size - 1; i++) {
			int max_left = 0, max_right = 0;
			for (int j = i; j >= 0; j--) {
				max_left = max(max_left, height[j]);// search the left part
			}
			for (int j = i; j < size; j++) {
				max_right = max(max_right, height[j]);// search the right part
			}
			ans += min(max_left, max_right) - height[i];
		}
		return ans;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0) return 0;
		int ans = 0;
		int size = height.size();
		vector<int> left_max(size), right_max(size);
		left_max[0] = height[0];
		for (int i = 1; i < size; i++) {
			left_max[i] = max(height[i], left_max[i - 1]);
		}
		right_max[size - 1] = height[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			right_max[i] = max(height[i], right_max[i + 1]);
		}
		for (int i = 1; i < size - 1; i++) {
			ans += min(left_max[i], right_max[i]) - height[i];
		}
		return ans;
	}
};

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int ans = 0;
		int left_max = 0, right_max = 0;
		while (left < right) {
			if (height[left] < height[right]) {
				height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
				++left;
			}
			else {
				height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
				--right;
			}
		}
		return ans;
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> height;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		height.push_back(t);
	}
	Solution s;
	cout << s.trap(height) << endl;
	return 0;
}