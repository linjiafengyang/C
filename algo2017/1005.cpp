#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minSum(vector<int>& A) {
		int size = A.size();
		vector<int> sum(size, 0);//sum[size-1]表示最后一个被选中时的最小和
		sum[0] = A[0];
		if (size > 1) sum[1] = A[1];

		for (int i = 2; i < size; i++) {
			sum[i] = min(sum[i - 2] + A[i], sum[i - 1] + A[i]);
		}
		if (size == 1) return sum[0];
		else return min(sum[size - 1], sum[size - 2]);
	}
};
// another solution
class Solution {
private:
	vector<int> f[2];
public:
	int minSum(vector<int>& A) {
		int n, i;
		n = A.size();
		if (n == 0) return 0;
		f[0].resize(n);
		f[1].resize(n);
		f[0][0] = 0;
		f[1][0] = A[0];
		for (i = 1; i < n; i++) {
			f[0][i] = f[1][i - 1];
			f[1][i] = A[i] + min(f[0][i - 1], f[1][i - 1]);
		}
		return min(f[0][n - 1], f[1][n - 1]);
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
	cout << s.minSum(A) << endl;
	return 0;
}