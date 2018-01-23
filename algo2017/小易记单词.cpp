#include <iostream>
#include <string>
#include <set>
using namespace std;
int main() {
    int n, m;
    set<string> s1, s2;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s1.insert(s);
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        s2.insert(s);
    }
    int ans = 0;
    for (set<string>::iterator it = s1.begin(); it != s1.end(); it++) {
        if (s2.find(*it) != s2.end()) {
            ans += it->length() * it->length();
        }
    }
    cout << ans << endl;
}