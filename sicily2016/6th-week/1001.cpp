#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2, s3;
    int T;
    cin >> T;
    while (T--) {
        cin >> s1 >> s2 >> s3;
        int flag = 1;
        while (flag) {
            int i;
            bool p = false;
            for (i = 0; i < s1.size(); i++ ) {
                if (s1[i] == s2[0]) {
                    int j, k;
                    for (j = i, k = 0; j < s1.size() && s2[k] != 0; j++, k++) {
                        if (s1[j] != s2[k]) {
                            p = false;
                            break;
                        }
                    }
                    if (s2[k] == 0) {
                        p = true;
                    }
                }
                if (p) {
                    break;
                }
            }
            if (p) {
                s1.replace(i, s2.size(), s3);
            }
            else if (i == s1.size()) {
                flag = 0;
            }
        }
        cout << s1 << endl;
    }
    return 0; 
}
