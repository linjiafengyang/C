#include <stdio.h>
int main() {
	int a, b;
	a = 077;//八进制数111111 
	b = a & 3;//111111 & 011 == 011 
	printf("a & b(decimal) 为 %d\n", b);
	b = b & 7;//011 & 111 == 011 
	printf("a & b(decimal) 为 %d\n", b);
	return 0;
}
