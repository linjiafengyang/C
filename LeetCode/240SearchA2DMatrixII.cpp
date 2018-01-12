class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size() - 1;
		int n = 0;
		while (m >= 0 && n < matrix[m].size()) {
			if (matrix[m][n] == target) return true;
			if (matrix[m][n] > target) m--;
			else n++;
		}
		return false;
	}
};