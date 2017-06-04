#include <stdio.h>
int main() {
	long int count = 1;
	while(count <= 300000000) {
		if(count % 100000000 ==0) {
			printf("Multiple is %d\n", count / 100000000);
		}
		++count;
	}
	return 0;
}

