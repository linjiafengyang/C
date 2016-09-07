#include <iostream>
using namespace std;
int main() {
    int m, d, i, j = 0, k, n;
    cin >> m >> d;
    while (m && d) {
        long long y[100][100] = {0};
        if (m >= d) {
            cout << 1 + d;
        }
        else {
            for (k = 0; k < m; k++) {
                y[k][0] = 1;
            }
            y[0][0] = 2;
            y[m][0] = 2;
            for (k = m + 1; k < d; k++) {
                for (n = 0; n < 32; n++) {
                    y[k][n] += y[k - 1][n] + y[k - m][n];
                    if (y[k][n] >= 10) {
                        y[k][n] -= 10;
                        y[k][n + 1] += 1;
                    }
                }
            }
            for (k = d - 2; k >= 0; k--) {
                for (n = 0; n < 32; n++) {
                    y[d - 1][n] += y[k][n];
                    if (y[d - 1][n] >= 10) {
                        y[d - 1][n] -= 10;
                        y[d - 1][n + 1] += 1;
                    }
                }
            }
        }
        bool p = false;
        for (i = 32; i >= 0; i--) {
            if (y[d - 1][i] != 0) {
                cout << y[d - 1][i];
                p = true;
                continue;
            }
            if (p) {
                cout << y[d - 1][i];
            }
        }
        cout << endl;
        cin >> m >> d;
    }
    return 0;
}
