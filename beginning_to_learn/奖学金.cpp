#include <stdio.h>
int main() {
	int N;
	int num;
	int grade;
	int gradeClass;
	int total;
	int totalprize;
	char a;
	char b;
	char name;
	scanf("%d", &N);
	total = 0;
	for(N;N>=1;N--) {
		scanf("%s", &name);
		scanf("%d", &grade);
		scanf("%d", &gradeClass);
		scanf("%c", &a);
		scanf("%c", &b);
		scanf("%d", &num);
		if((grade > 80)&&(num >= 1)) {
			total = total + 8000;
		}
		if((grade > 85)&&(gradeClass > 80)) {
			total = total + 4000;
		}
		if(grade > 90) {
			total = total + 2000;
		}
		if((grade > 85)&&(b == 'Y')) {
			total = total + 1000;
		}
		if((gradeClass > 80)&&(a == 'Y')) {
			total = total + 850;
		}
		total=total;
		totalprize+=total;
	}
	printf("%d", total);
	return 0;
}

