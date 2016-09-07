#include <iostream>
#include <string>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int i, start = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == '_') {
                int j, k = 0;
                char a[1000];
                for (j = start; j < i; j++, k++) {
                    a[j] = s[i - 1 - k];
                }
                for (j = start; j < i; j++) {
                    s[j] = a[j];
                }
                start = i + 1;
            } 
        }
        char a[1000];
        int k = 0;
        for (int j = start; j < s.size(); j++, k++) {
            a[j] = s[s.size() - 1 - k];
        }
        for (int j = start; j < s.size(); j++) {
            s[j] = a[j];
        }
        cout << s << endl;
    }
    return 0;
}
