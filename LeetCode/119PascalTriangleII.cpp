#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int> > res;
		// 行数
		res.resize(rowIndex + 1);
		for (int i = 0; i < rowIndex + 1; i++) {
			// 每一行的列数
			res[i].resize(i + 1);
			// 初始化每一行的头尾，置为1
			res[i][0] = 1;
			res[i][i] = 1;
		}
		// 第0行和第1行不用算，已经初始化了
		for (int i = 2; i < rowIndex + 1; i++) {
			for (int j = 1; j < i; j++) {
				// 当前行当前列的数等于前一行前一列的数加上前一行当前列的数
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
		}
		return res[rowIndex];
	}
};
// another version
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
       	vi[0] = 1;
        for (int i = 1; i <= rowIndex ; ++i)
        {
        	for (int j = i; j > 0; --j)
        	{
	        	vi[j] = vi[j] + vi[j-1];
        	}
        }
        return vi;
    }
};
int main() {
	Solution s;
	int rowIndex;
	cin >> rowIndex;
	vector<int> res = s.getRow(rowIndex);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}