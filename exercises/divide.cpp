/*
除法：给定一个n，abcde/fghij=n，a~g恰好为0~9的数字
62
79546/01283=62
94736/01528=62
 */
#include <iostream>
#include <cstring>
using namespace std;
bool check(int x, int y) {
	char s[15];
	sprintf(s, "%05d%05d", x, y);
	for (char i = '0'; i <= '9'; i++) {
		if (!strchr(s, i)) return false;
	}
	return true;
}
int main() {
	int abcde, fghij, n;
	cin >> n;
	for (fghij = 1234; fghij <= 98765; fghij++) {
		abcde = n * fghij;
		if (abcde < 100000 && check(abcde, fghij)) {
			printf("%05d/%05d=%d\n", abcde, fghij, n);
		}
	}
	return 0;
}