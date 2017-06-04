#include <stdio.h>
int main(){
	int counter;
	int number;
	int largest;
	
	printf("Enter the first number:");
	scanf("%d",&largest);
	counter=2;
	
	while(counter<=10){
		printf("Enter next number:");
		scanf("%d",&number);
		
		if(number>largest){
			largest=number;
		}
		counter++;
	}
	
	printf("Largest is %d\n",largest);
	return 0;
}
