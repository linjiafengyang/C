#include <stdio.h>
int main(){
	int largest,smallest,temp;
	int integer1,integer2,integer3;
	printf("Input 5 integer:");
	scanf("%d%d%d%d%d",&largest,&smallest,&integer1,&integer2,&integer3);
	if(smallest>largest){
		temp = largest;
		largest = smallest;
		smallest = temp;
	}
	if(integer1>largest){
		largest = integer1;
	}
	if(integer1<smallest){
		smallest = integer1;
	}
	if(integer2>largest){
		largest = integer2;
	}
	if(integer2<smallest){
		smallest = integer2;
	}
	if(integer3>largest){
		largest = integer3;
	}
	if(integer3<smallest){
		smallest = integer3;
	}
	printf("The largest value is %d\n",largest);
	printf("The smallest value is %d\n",smallest);
	return 0;
}
