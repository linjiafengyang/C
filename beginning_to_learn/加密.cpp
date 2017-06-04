#include <stdio.h>
int main() {
	int first;
	int second;
	int third;
	int fourth;
	int digit;
	int temp1;
	int temp2;
	int encryptednumber;
	printf("Enter a four digit number to be encrypted: ");
	scanf("%d", &digit);
	temp1 = digit;
	first = (temp1 / 1000 + 7) % 10;
	temp2 = temp1 % 1000;
	
	second = (temp2 / 100 + 7) % 10;
	temp1 = temp2 % 100;
	
	third = (temp1 / 10 + 7) % 10;
	temp2 = temp1 % 10;
	
	fourth = (temp2 + 7) % 10;
	
	temp1 = first;
	first = third * 1000;
	third = temp1 * 10;
	
	temp1 = second;
	second = fourth * 100;
	fourth = temp1 * 1;
	
	encryptednumber = first + second + third + fourth;
	printf("Encrypted number is %d\n", encryptednumber);
	return 0;
	
} 

