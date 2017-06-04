#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int a, b, c, hh, mm, ss;
	scanf("%d %d", &a, &b);
	c = (b - a) / 100;
	if ((b - a) % 100 >= 50) {
		c++;
	}
	hh = c / 3600;
	mm = c % 3600 / 60;
	ss = c % 60;
	printf("%02d:%02d:%02d\n", hh, mm, ss);
	system("pause");
	return 0;
}