#include <stdio.h>
typedef struct student {
	int math;
	int english;
	int code;
	int total;
	int num;
}student;
int main() {
	int n;
	student stu[1000];
	scanf("%d", &n);
	int i, j;
	for(i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].num, &stu[i].math, &stu[i].english, &stu[i].code);
		stu[i].total = stu[i].math + stu[i].english + stu[i].code;
	}
	student temp;
	for(i = 1; i < n; i++) {
		for(j = 0; j < n - 1; j++) {
			if(stu[j].total > stu[j + 1].total) {
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
			else if(stu[j].total == stu[j + 1].total) {
				if(stu[j].num < stu[j + 1].num) {
					temp = stu[j + 1];
					stu[j + 1] = stu[j];
					stu[j] = temp;
				}
			}
		}
	}
	for(i = n - 1; i >= n - 5; i--) {
		printf("%d %d %d %d %d\n", stu[i].num, stu[i].math, stu[i].english, stu[i].code, stu[i].total);
	}
}
