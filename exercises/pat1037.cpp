#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int g1, s1, k1, g2, s2, k2, g3, s3, k3;
	int sum1, sum2, sum3;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	sum1 = (g1 * 17 + s1) * 29 + k1;
	sum2 = (g2 * 17 + s2) * 29 + k2;
	sum3 = sum2 - sum1;
	g3 = sum3 / (17 * 29);
	s3 = (sum3 - g3 * (17 * 29)) / 29;
	k3 = (sum3 - g3 * (17 * 29) - s3 * 29);
	if (sum3 < 0) {
		cout << "-" << abs(g3) << "." << abs(s3) << "." << abs(k3) << endl;
	}
	else {
		cout << g3 << "." << s3 << "." << k3 << endl;
	}
	return 0;
}