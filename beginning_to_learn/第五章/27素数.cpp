#include <stdio.h>
#include <math.h>
int prime(int n);
int prime1(int n);
int main() {
	int loop;
	int count = 0;
	printf("The prime numbers from 1 to 10000 are:\n");
	for(loop = 1; loop <= 10000; loop++) {
		if(prime(loop)) {
			++count;
			printf("%6d", loop);
			if(count % 10 == 0) {
				printf("\n");
			}
		}
	}
	printf("\n\n");
	for(loop = 1; loop <= 10000; loop++) {
		if(prime1(loop)) {
			++count;
			printf("%6d", loop);
			if(count % 10 == 0) {
				printf("\n");
			}
		}
	}
	return 0;
}
int prime(int n) {
	int loop1;
	for(loop1 = 2; loop1 <= n / 2; loop1++) {
		if(n % loop1 == 0) {
			return 0;
		}
	}
	return 1;
}
int prime1(int n) {
	int loop1;
	for(loop1 = 2; loop1 <= (int)sqrt(n); loop1++) {
		if(n % loop1 == 0) {
			return 0;
		}
	}
	return 1;	
}
