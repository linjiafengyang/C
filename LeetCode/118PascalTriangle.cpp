#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		// 行数
		res.resize(numRows);
		for (int i = 0; i < numRows; i++) {
			// 每一行的列数
			res[i].resize(i + 1);
			// 初始化每一行的头尾，置为1
			res[i][0] = 1;
			res[i][i] = 1;
		}
		// 第0行和第1行不用算，已经初始化了
		for (int i = 2; i < numRows; i++) {
			for (int j = 1; j < i; j++) {
				// 当前行当前列的数等于前一行前一列的数加上前一行当前列的数
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
		}
		return res;
	}
};
int main() {
	Solution s;
	int numRows;
	cin >> numRows;
	vector<vector<int> > res = s.generate(numRows);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}