#include <iostream>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		int d[n + 10];
		d[1] = 1;
		d[2] = 2;
		for (int i = 3; i < n + 1; i++) {
			d[i] = d[i - 1] + d[i - 2];
		}
		return d[n];
	}
};
int main() {
	int n;
	cin >> n;
	Solution s;
	cout << s.climbStairs(n) << endl;
	return 0;
}