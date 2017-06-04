#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randValue(int level); 
void correctMessage(void);
void incorrectMessage(void);
void multiplication(void);
int main() {
	srand(time(NULL));
	multiplication();
	return 0;
}
int randValue(int level) {
	switch(level) {
		case 1:
			return rand() % 10;
		case 2:
			return rand() % 100;
		case 3:
			return rand() % 1000;
		default:
			return rand() % 10;
	}
}
void multiplication(void) {
	int i;
	int x;
	int y;
	int response;
	int right = 0;
	int wrong = 0;
	int gradelevel;
	printf("Enter the grade-level ( 1 to 3):");
	scanf("%d", &gradelevel);
	for(i = 1; i <= 10; i++) {
		x = rand() % 10;
		y = rand() % 10;
		printf("How much is %d times %d?\n", x, y);
		scanf("%d", &response);
		while(response != x * y) {
			wrong++;
			incorrectMessage();
			scanf("%d", &response);
		}
		right++;
		correctMessage();
	}
	if((double)right / (right + wrong) < .75) {
		printf("Please ask your instructor for extra help.\n");
	}
	printf("That's all for now.Bye.\n");
}
void correctMessage(void) {
	switch(rand() % 4) {
		case 0:
			printf("Very good!\n\n");
			break;
		case 1:
			printf("Excellent!\n\n");
			break;
		case 2:
			printf("Nice work!\n\n");
			break;
		case 3:
			printf("Keep up the good work!\n\n");
			break;
	}
}
void incorrectMessage(void) {
	switch(rand() % 4) {
		case 0:
			printf("No.Please try again.\n?");
			break;
		case 1:
			printf("Wrong.Try once more.\n?");
			break;
		case 2:
			printf("Don't give up!\n?");
			break;
		case 3:
			printf("No.Keep trying.\n?");
			break;
	}
}
