#include <iostream>
using namespace std;
int main() {
    int t;
    int i;
    cin >> t;
    cin.get();
    string a[1000];
    for (i = 0; i < t; i++) {
        getline(cin, a[i], '*');
    }
    for (i = 0; i < t; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}                                 
