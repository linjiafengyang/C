#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int tx[51], ty[51];
    int gx, gy, wt, dt;
    cin >> n;
    int walkTime = INT_MAX, driveTime = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> tx[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> ty[i];
    }
    cin >> gx >> gy >> wt >> dt;
    walkTime = (abs(gx) + abs(gy)) * wt;
    for (int i = 0; i < n; i++) {
        driveTime = min(driveTime, (abs(ty[i]) + abs(tx[i])) * wt + (abs(ty[i] -gy) + abs(tx[i] - gx)) * dt);
    }
    cout << min(driveTime, walkTime) << endl;
    return 0;
}