#include <iostream>
using namespace std;
int main() {
	int n, i;
	int a1 = 0, a2 = 0, a3 = 0;
	int aj = 0, ac = 0, ab = 0, bj = 0, bc = 0, bb = 0;
	char x, y, blank;
	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> x >> y;
		if( x == 'C' && y == 'J') {
			a1++;
			ac++;
			continue;
		}
		if(x == 'J' && y == 'B') {
			a1++;
			aj++;
			continue;
		}
		if(x == 'B' && y == 'C') {
			a1++;
			ab++;
			continue;
		}
		if(x == 'C' && y == 'C') {
			a2++;
			continue;
		}
		if(x == 'J' && y == 'J') {
			a2++;
			continue;
		}
		if(x == 'B' && y == 'B') {
			a2++;
			continue;
		}
		if(x == 'C' && y == 'B') {
			a3++;
			bb++;
			continue;
		}
		if(x == 'J' && y == 'C') {
			a3++;
			bc++;
			continue;
		}
		if(x == 'B' && y == 'J') {
			a3++;
			bj++;
			continue;
		}
	}
	cout << a1 << " " << a2 << " " << a3 << endl;
	cout << a3 << " " << a2 << " " << a1 << endl;
	if(ab >= ac && ab >= aj) {
		cout << "B";
	}
	else if(ac >= aj) {
		cout << "C";
	}
	else {
		cout << "J";
	}
	if(bb >= bc && bb >= bj) {
		cout << " B";
	}
	else if(bc >= bj) {
		cout << " C";
	}
	else {
		cout << " J";
	}
} 
