#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void (guessGame(void));
int main() {
	srand(time(NULL));
	guessGame();
	return 0;
}
void guessGame(void) {
	int x;
	int guess;
	int response;
	int total = 1; 
	do {
		x = 1 + rand() % 1000;
		printf("\nI have a number between 1 and 1000.\n");
		printf("Can you guess my number?\n");
		printf("Please type your first guess.\n?");
		scanf("%d", &guess);
		while(guess != x) {
			if(guess < x) {
				printf("Too low.Try again.\n?");
			}
			else {
				printf("Too high.Try again.\n?");
			}
			scanf("%d", &guess);
			total++;
		}
		printf("\nExcellent!You guessed the number!\n");
		if(total < 10) {
			printf("Either you know the secret or you got lucky!\n");
		}
		else if(total == 10) {
			printf("Ahah!You know the secret!\n");
		}
		else {
			printf("You should be able to do better!\n\n");
		}
		printf("Would you like to play again?\n");
		printf("Please type (1 = yes, 2 = no)?");
		scanf("%d", &response);
	} while(response == 1);
}
