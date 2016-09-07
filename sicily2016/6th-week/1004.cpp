#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    string s[t + 2];
    int i;
    for (i = 0; i < t; i++) {
        cin >> s[i];
    }
    string a;
    cin >> a;
    int j, k;
    int len = 0, l;
    int c = a.size();
    i = 0;
    while (c > 0) {
        bool p = false;
        string temp;
        for (l = 0; l < t; l++) {
            if (a[i] == s[l][0]) {
                for (j = i, k = 0; j < a.size() && s[l][k] != 0; j++, k++) {
                    if (a[j] != s[l][k]) {
                        break;
                    }
                }
               if (s[l][k] == 0) {
                   if (s[l].size() > len) {
                       temp = s[l];
                       len = s[l].size();
                       p = true;
                   }
               }
            }
       }
       if (p) {
              i += temp.size();
              c -= temp.size();
              if (c > 0) {
                 cout << temp << " ";
              }
              else {
                 cout << temp << endl;
              }
       }
       else {
          c--;
          i++;
          if (c > 0) {
             cout << a[i - 1] << " ";
          }
          else {
            cout << a[i - 1] << endl;
          }
       }
       len = 0;
    }
    return 0;
}
