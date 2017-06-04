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
		if((a=='Y')&&gradeClass>80){
			total+=850;
		}
		if(grade>85){
			if(num>0){
				total+=8000;
			}
		} 
		if(grade>85){
			if(gradeClass>80){
				total+=4000;
			}
			if(b=='Y'){
				total+=1000;
			}
		}
		if(grade>90){
			total+=2000;
		}
	}
		totalprize+=total;
		printf("%d\n", total);
		return 0;
}


