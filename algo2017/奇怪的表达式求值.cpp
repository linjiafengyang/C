#include <iostream>
#include <string>
using namespace std;
bool isNumber(char c) {
    return c >= '0' && c <= '9';
}
int main() {
    string s;
    cin >> s;
    int num = 0, ans = 0;
    char op = '+';
    for (int i = 0; i < s.length(); i++) {
        if (isNumber(s[i])) {
            num = num * 10 + s[i] - '0';
        }
        else {
            if (op == '+') ans = ans + num;
            else if (op == '*') ans = ans * num;
            else ans = ans - num;
            op = s[i];
            num = 0;
        }
    }
    if (op == '+') ans = ans + num;
    else if (op == '*') ans = ans * num;
    else ans = ans - num;
    cout << ans << endl;
    return 0;
}