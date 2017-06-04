#include <stdio.h>
int main() {
	int grade;
	int aCount = 0;
	int bCount = 0;
	int cCount = 0;
	int dCount = 0;
	int fCount = 0;
	double averageGrade;
	printf("Enter the letter grades.\n");
	printf("Enter the EOF character to end input.\n");
	while((grade = getchar()) != EOF) {
		switch(grade) {
			case 'A':
			case 'a':
				++aCount;
				break;
			case 'B':
			case 'b':
				++bCount;
				break;
			case 'C':
			case 'c':
				++cCount;
				break;
			case 'D':
			case 'd':
				++dCount;
				break;
			case 'F':
			case 'f':
				++fCount;
				break;
			case '\n':
			case '\t':
			case ' ':
				break;
			default:
				printf("Incorrect letter grade entered.");
				printf("Enter a new grade.\n");
				break;
		}
	}
	printf("\nThe totals for each letter grade are:\n");
	printf("A: %d\n", aCount);
	printf("B: %d\n", bCount);
	printf("C: %d\n", cCount);
	printf("D: %d\n", dCount);
	printf("F: %d\n", fCount);
	averageGrade = (4 * aCount + 3 * bCount + 2 * cCount + dCount)/
					(aCount + bCount + cCount + dCount + fCount);
	if(averageGrade > 3.4) {
		printf("Average grade is A\n");
	}
	else if(averageGrade > 2.4) {
		printf("Average grade is B\n");
	}
	else if(averageGrade > 1.4) {
		printf("Average grade is C\n");
	} 
	else if(averageGrade > 0.4) {
		printf("Average grade is D\n");
	}
	else {
		printf("Average grade is F\n");
	}
	return 0;
} 
