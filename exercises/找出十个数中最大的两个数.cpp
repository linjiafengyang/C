#include <stdio.h>
int main(){
	int counter;
	int number;
	int largest;
	int secondlargest=0;
	printf("Enter the first number:");
	scanf("%d",&largest);
	counter=2;
	
	while(counter<=10){
		printf("Enter next number:");
		scanf("%d",&number);
		
		if(number>largest){
			secondlargest=largest;
			largest=number;
		}
		else
			if(number>secondlargest){
				secondlargest=number;
			}
		
		++counter;
	}
	
	printf("Largest is %d\n",largest);
	printf("Secondlargest is %d\n",secondlargest);
	return 0;	
} 
