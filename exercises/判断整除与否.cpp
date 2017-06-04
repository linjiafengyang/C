#include <stdio.h>
int main(){
	int integer1,integer2;
	printf("Input two integers:");
	scanf("%d%d",&integer1,&integer2);
	if(integer1%integer2==0){
		printf("%d is a multiple of %d",integer1,integer2);
		printf(" by a factor of %d\n",integer1/integer2);
	}
	if(integer1%integer2!=0){
		printf("%d is not a multiple of %d",integer1,integer2);
	}
	return 0;
}
