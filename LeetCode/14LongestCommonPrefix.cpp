#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		string result = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			for (int j = 0; j < result.length(); j++) {
				if (result[j] != strs[i][j]) {
					result = result.substr(0, j);
					break;
				}
			}
		}
		return result;
	}
};
/*
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result = "";
		for (int index = 0; strs.size() > 0; result += strs[0][index], index++) {
			for (int i = 0; i < strs.size(); i++) {
				if (index >= strs[i].size() || (i > 0 && strs[i][index] != strs[i - 1][index])) {
					return result;
				}
			}
		}
		return result;
	}
};
*/
int main() {
	Solution s;
	vector<string> strs(4);
	for (int i = 0; i < 4; i++) {
		cin >> strs[i];
	}
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}