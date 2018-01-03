#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minDifference(vector<int> A) {
		int difference;
		sort(A.begin(), A.end());
		difference = abs(A[1] - A[0]);
		for (int i = 1; i < A.size() - 1; i++) {
			if (abs(A[i] - A[i + 1]) < difference) {
				difference = abs(A[i] - A[i + 1]);
			}
		}
		return difference;
	}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << s.minDifference(A) << endl;
	return 0;
}
