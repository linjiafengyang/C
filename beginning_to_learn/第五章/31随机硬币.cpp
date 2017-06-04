#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int flip();
int main() {
	int loop;
	int headCount = 0;
	int tailCount = 0;
	srand(time(NULL));
	for(loop = 1; loop <= 100; loop++) {
		if(flip() == 0) {
			tailCount++;
		}
		else {
			headCount++;
		}
		if(loop % 10 == 0) {
			printf("\n");
		}
	}
	printf("\nThe total number of Heads was %d\n", headCount);
	printf("The total number of Tails was %d\n", tailCount);
	return 0;
}
int flip() {
	int Hort = rand() % 2;
	if(Hort == 0) {
		printf("Tails ");
	}
	else {
		printf("Heads ");
	}
	return Hort;
}
