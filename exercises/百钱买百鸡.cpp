#include <stdio.h>
int main() {
	int x, y, z;
	for(x = 0; x <= 100; x++) {
		for(y = 0; y <= 100; y++) {
			for(z = 0; z <= 100; z++) {
				if(5 * x + 3 * y + 1 / 3 * z == 100 && x + y + z == 100) {
					printf("����%2dֻ ĸ��%2dֻ С��%2dֻ\n", x, y, z);
				}
			}
		}
	}
	return 0;
}
