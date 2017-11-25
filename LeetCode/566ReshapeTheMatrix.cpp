#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
		int r1 = nums.size();
		int c1 = nums[0].size();
		if (r1 * c1 != r * c) return nums;
		vector<vector<int> > res(r, vector<int>(c, 0));// 这一步初始化二维非常重要
		int rows = 0, cols = 0;
		for (int i = 0; i < r1; i++) {
			for (int j = 0; j < c1; j++) {
				res[rows][cols] = nums[i][j];
				cols++;
				if (cols == c) {
					rows++;
					cols = 0;
				}
			}
		}
		return res;
	}
};
int main() {
	Solution s;
	int r1, c1;
	cin >> r1 >> c1;
	vector<vector<int> > nums(r1, vector<int>(c1, 0));// 这一步初始化二维非常重要
	int t;
	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			//cin >> t;
			cin >> nums[i][j];
		}
	}
	int r, c;
	cin >> r >> c;
	vector<vector<int> > temp = s.matrixReshape(nums, r, c);
	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp[0].size(); j++) {
			cout << temp[i][j] << " ";
		}
	}
	return 0;
}