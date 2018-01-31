#include <iostream>
#include <vector>
using namespace std;
// 超时
// class Solution {
// public:
// 	int maxArea(vector<int>& height) {
// 		int res = 0;
// 		for (int i = 0; i < height.size(); i++) {
// 			for (int j = i + 1; j < height.size(); j++) {
// 				res = max(res, min(height[i], height[j]) * (j - i));
// 			}
// 		}
// 		return res;
// 	}
// };
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res= 0, left = 0, right = height.size() - 1;
		while (left < right) {
			res = max(res, min(height[left], height[right]) * (right - left));
			if (height[left] < height[right]) left++;
			else right--;
		}
		return res;
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
	cout << s.maxArea(height) << endl;
	return 0;
}