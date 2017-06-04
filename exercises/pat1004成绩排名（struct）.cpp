#include <stdio.h>
struct student {
	char stu_name[20];
	char stu_id[20];
	int stu_grade;
};
int main() {
	int i, n;
	int max, min;
	scanf("%d", &n);
	struct student stu[n];
		for(i = 0; i < n; i++) {
			scanf("%s%s%d", stu[i].stu_name, stu[i].stu_id, &stu[i].stu_grade);
		}
		max = 0;
		min = 0;
		for(i = 1; i < n; i++) {
			if(stu[i].stu_grade > stu[max].stu_grade) {
				max = i;
			}
			if(stu[i].stu_grade < stu[min].stu_grade) {
				min = i;
			}
		}
		printf("%s %s\n", stu[max].stu_name, stu[max].stu_id);
		printf("%s %s\n", stu[min].stu_name, stu[min].stu_id);
	return 0;
}
