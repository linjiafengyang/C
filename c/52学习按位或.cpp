#include <stdio.h>
int main() {
	int a, b;
	a = 077;//八进制数111111 
	b = a | 3;//111111 | 011 == 111111 
	printf("a | b(decimal) 为 %d\n", b);
	b = b | 7;//111111 | 111 == 111111 
	printf("a | b(decimal) 为 %d\n", b);
	return 0;
}
