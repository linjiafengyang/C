#include <iostream>
#include <set>
using namespace std;
struct Frac {
    int p, q;
    bool operator<(const Frac &frac) const {
        if (p != frac.p) return p < frac.p;
        if (q != frac.q) return q < frac.q;
        return false;
    }
};
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    int w, x, y, z;
    set<Frac> s;
    cin >> w >> x >> y >> z;
    Frac f;
    for (int i = w; i <= x; i++) {
        for (int j = y; j <= z; j++) {
            int div = gcd(i, j);
            f.p = i / div;
            f.q = j / div;
            s.insert(f);
        }
    }
    cout << s.size() << endl;
    return 0;
}