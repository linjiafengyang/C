#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int i, count = 0, index[1000];
    for (i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index[count++] = i; 
        }
    }
    cout << s << endl;
    for (i = 0; i < count; i++) {
        int start = index[i];
        for (int j = index[i] + 1; j < s.size(); j++) {
            cout << s[j];
        }
        cout << " ";
        for (int j = 0; j < start; j++) {
            cout << s[j]; 
        }
        cout << endl;
    }
    return 0;
}
