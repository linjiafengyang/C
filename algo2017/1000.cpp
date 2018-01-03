#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPartition(vector<int> A, int w) {
        sort(A.begin(), A.end());
        int num = 0;
        int temp = 0;
        int i = 0, j = A.size()-1;
        while (A[j] > w) j--;
        if (j == 0) num = 1;
        while (i <= j && j >= 0) {
        	temp = A[i] + A[j];
        	if (temp > w) {
        		j--;      		
        	} else {
        		i++;
        		j--;
			}
        	num++;
        	temp = 0;
        }
        return num;
    }
};
// another solution
class Solution {
public:
	int minPartition(vector<int> A, int w) {
		int res, n, i, j;
		n = A.size();
		sort(A.begin(), A.end());
		res = 0;
		for (i = 0, j = n - 1; i <= j; j--) {
			if (A[i] + A[j] <= w) i++;
			res++;
		}
		return res;
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
    int w;
    cin >> w;
    cout << s.minPartition(A, w) << endl;
    return 0;
}