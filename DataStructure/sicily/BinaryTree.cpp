#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int T, a, b, lc, rc, t = 1;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		lc = rc = 0;
		while (a != 1 || b != 1) {
			if (a > b) {
				int c = a / b;
				a %= b;
				if (!a) --c, a = 1;
				lc += c;
			}
			else {
				int c = b / a;
				b %= a;
				if (!b) --c, b = 1;
				rc += c;
			}
		}
		cout << "Scenario #" << t++ << endl << lc << " " << rc << endl;
	}
	return 0;
}