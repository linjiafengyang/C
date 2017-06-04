#include <stdio.h>
int main() {
	static int count = 1;
	printf("%d\n", count);
	count++;
	main();
	return 0;
}
