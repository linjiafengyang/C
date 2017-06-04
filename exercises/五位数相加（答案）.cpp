#include <stdio.h>
int main(){
	int number;
	int temp1;
	int temp2;
	printf("Enter a five-digit number:");
	scanf("%d",&number);
	printf("%d   ",number/10000);
	temp2=number%10000;
	printf("%d   ",temp2/1000);
	temp1=temp2%1000;
	printf("%d   ",temp1/100);
	temp2=temp1%100;
	printf("%d   ",temp2/10);
	temp1=temp2%10;
	printf("%d\n",temp1);
	return 0;
}
