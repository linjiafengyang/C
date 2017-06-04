#include <stdio.h>
int main(){
	int integer;
	printf("Input an integer:");
	scanf("%d",&integer);
	if(integer%2==0){
		printf("%d is an even integer\n",integer);
	}
	if(integer%2!=0){
		printf("%d is an odd integer\n",integer);
	}
	return 0;
} 
