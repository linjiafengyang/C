#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n;
    int a[1002] = {0};
    vector<int> v;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s.find(a[i]) == s.end()) {
            s.insert(a[i]);
            v.push_back(a[i]);
        }
    }
    cout << v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--) {
        cout << " " << v[i];
    }
    cout << endl;
    return 0;
}