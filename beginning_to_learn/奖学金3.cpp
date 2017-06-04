#include <stdio.h>
#include <string.h>
int main() {
	int N;
	int i;
	int sum = 0;
	int total = 0;
	int totalprize = 0;
	int grade, gradeClass, num;
	char name[25], a1, a2, mingzi[25];
	scanf("%d", &N);
	for(i=0;i<N;i++) {
		scanf("%s %d %d %c %c %d", &name, &grade, &gradeClass, &a1, &a2, &num);
		if(grade > 80 && num >= 1) {
			sum = sum + 8000;
		}
		if(grade >85 && gradeClass > 80) {
			sum = sum + 4000;
		}
		if(grade > 90) {
			sum = sum + 2000;
		}
		if(grade > 85 && a2 == 'Y') {
			sum = sum + 1000;
		}
		if(gradeClass > 80 && a1 == 'Y' ) {
			sum = sum + 850;
		}
		totalprize = totalprize + sum;
		if(total < sum) {
			total = sum;
			strncpy(mingzi,name, 25);
		}
		sum = 0; 
	}
	printf("%s\n%d\n%d\n", mingzi, total, totalprize);
	return 0;
} 

