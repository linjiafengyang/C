#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int i;
    string name[1000];
    string code[1000];
    double cost[1000];
    for (i = 0; i < t; i++) {
        cin >> name[i] >> code[i] >> cost[i];
        cout << resetiosflags(ios::right);
        cout << setiosflags(ios::left) << setw(15) << name[i] 
			 << setiosflags(ios::left) << setw(15) << code[i];
        cout << setiosflags(ios::right) << setprecision(2) << setiosflags(ios::fixed)
			 << setw(10) << cost[i] << endl;
    }
}
