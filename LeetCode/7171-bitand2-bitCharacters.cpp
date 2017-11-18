#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	int size = bits.size();
        int i = 0;
        while (i < size - 1) {
        	i += bits[i] + 1;
        }
        return i == size - 1;
    }
};
int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> bits(n);
    for (int i = 0; i < n; i++) {
        cin >> bits[i];
    }
    cout << s.isOneBitCharacter(bits) << endl;
    return 0;
}
