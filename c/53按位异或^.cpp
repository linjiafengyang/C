#include <stdio.h>
int main() {
	int a, b;
	a = 077;//�˽�����111111 
	b = a ^ 3;//111111 ^ 011 == 111100 
	printf("a ^ b(decimal) Ϊ %d\n", b);
	b = b ^ 7;//111100 ^ 111 == 111011 
	printf("a ^ b(decimal) Ϊ %d\n", b);
	return 0;
}
