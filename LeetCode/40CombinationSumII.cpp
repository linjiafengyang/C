#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		vector<int> combination;
		sort(candidates.begin(), candidates.end());
		combinationSum2(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum2(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& combination, int begin) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
			if (i == begin || candidates[i] != candidates[i - 1]) {
				combination.push_back(candidates[i]);
				combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
				combination.pop_back();
			}
		}
	}
};
int main() {
	int n;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	int target;
	cin >> target;
	Solution s;
	vector<vector<int> > res = s.combinationSum2(nums, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}