#include <stdio.h>
int main(){
	int age;
	do{
		printf("enter your age:");
		scanf("%d",&age);
		if(age<=0){
			printf("your age must be positive.\n");
		}
	}while(age<=0);
} 