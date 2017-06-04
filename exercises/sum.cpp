#include <stdio.h>
int main(){
	int integer1,integer2,sum;
	printf("enter first integer\n");
	scanf("%d",&integer1);
	printf("enter second integer\n");
	scanf("%d",&integer2);
	sum = integer1 + integer2;
	printf("sum is %d",sum);
	return 0;
}