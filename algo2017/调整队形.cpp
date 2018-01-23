#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    int B = 0;
    int G = 0;
    int sumB = 0;
    int sumG = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            G++;
            sumG += i;
        }
        else {
            B++;
            sumB += i;
        }
    }
    int ret1 = sumB - B * (B - 1) / 2;
    int ret2 = sumG - G * (G - 1) / 2;
    cout << min(ret1, ret2) << endl;
    return 0;
}