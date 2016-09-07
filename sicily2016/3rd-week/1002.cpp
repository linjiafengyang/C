#include <iostream>
void addxy(int x, int y, int total);
void subxy(int &x, int &y, int &total);
void printtotal(int total) {
	printf("Total in Main: %d\n", total);
}
int main() {
	int x, y, total;
	x = 10;
    y = 5;
    total = 0;
    printtotal(total);
    addxy(x, y, total);
    printtotal(total);
    subxy(x, y, total);
    printtotal(total);
    return 0;
}
void addxy(int x, int y, int total) {
	total = x + y;
	printf("Total from inside addxy: %d\n", total);
}
void subxy(int &x, int &y, int &total) {
	total = x - y;
	printf("Total from inside subxy: %d\n", total);
}

