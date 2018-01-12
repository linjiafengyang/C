class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		vector<int> temp;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				temp.push_back(matrix[i][j]);
			}
		}
		for (int i = 0; i < temp.size(); i++) {
			if (target == temp[i]) return true;
		}
		return false;

	}
};