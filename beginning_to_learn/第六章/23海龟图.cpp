#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
void getCommands(int commands[][2]);
int turnRight(int d);
int turnLeft(int d);
void movePen(int down, int a[][50], int dir, int dist);
void printArray(int a[][50]);
int main() {
	int floor[50][50] = {0};
	int penDown = FALSE;
	int command;
	int direction = 0;
	int commandArray[MAX][2] = {0};
	int distance;
	int count = 0;
	getCommands(commandArray);
	command = commandArray[count][0];
	while(command != 0) {
		switch(command) {
			case 1:
				penDown = FALSE;
				break;
			case 2:
				penDown = TRUE;
				break;
			case 3:
				direction = turnRight(direction);
				break;
			case 4:
				direction = turnLeft(direction);
				break;
			case 5:
				distance = commandArray[count][1];
				movePen(penDown, floor, direction, distance);
				break;
			case 6:
				printf("\nThe drawing is:\n\n");
				printArray(floor);
				break;
		}
		command = commandArray[++count][0];
	}
	return 0;
}
void getCommands(int commands[][2]) {
	int i;
	int tempCommand;
	printf("Enter command (9 to end input):");
	scanf("%d", &tempCommand);
	for(i = 0; tempCommand != 9 && i < MAX; i++) {
		commands[i][0] = tempCommand;
		if(tempCommand == 5) {
			scanf(",%d", &commands[i][1]);
		}
		printf("Enter command (9 to end input):");
		scanf("%d", &tempCommand);
	}
	commands[i][0] = 9;
}
int turnRight(int d) {
	return ++d > 3 ? 0 : d; 
}
int turnLeft(int d) {
	return --d < 0 ? 3 : d;
}
void movePen(int down, int a[][50], int dir, int dist) {
	int i;
	int j;
	static int xPos = 0;
	static int yPos = 0;
	switch(dir) {
		case 0:
			for(j = 1; j <= dist && yPos + j < 50; j++) {
				if(down) {
					a[xPos][yPos + j] = 1;
				}
			}
			yPos += j - 1;
			break;
		case 1:
			for(i = 1; i <= dist && xPos + i < 50; i++) {
				if(down) {
					a[xPos + i][yPos] = 1;
				}
			}
			xPos += i - 1;
			break;
		case 2:
			for(j = 1; j <= dist && yPos - j >= 0; j++) {
				if(down) {
					a[xPos][yPos - j] = 1;
				}
			}
			yPos -= j - 1;
			break;
		case 3:
			for(i = 1; i <= dist && xPos - i >= 0; i++) {
				if(down) {
					a[xPos - i][yPos] = 1;
				}
			}
			xPos -= i - 1;
			break;
	}
}
void printArray(int a[][50]) {
	int i;
	int j;
	for(i = 0; i < 50; i++) {
		for(j = 0; j < 50; j++) {
			putchar(a[i][j] ? '*' : ' ');
		}
		putchar('\n');
	}
}


