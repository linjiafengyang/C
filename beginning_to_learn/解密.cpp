#include <stdio.h>
int main() {
	int first;
	int second;
	int third;
	int fourth;
	int decrypted;
	int temp1;
	int temp2;
	int encryptednumber;
	printf("Enter a four digit encrypted number:");
	scanf("%d", &encryptednumber);
	temp1 = encryptednumber;
	
	first = temp1 / 1000;
	temp2 = temp1 % 1000;
	
	second = temp2 / 100;
	temp1 = temp2 % 100;
	
	third = temp1 / 10;
	temp2 = temp1 % 10;
	
	fourth = temp2;
	
	temp1 = (first + 3) % 10;
	first = (third + 3) % 10;
	third = temp1;
	
	temp1 = (second + 3) % 10;
	second = (fourth + 3) % 10;
	fourth = temp1;
	decrypted = (first * 1000) + (second * 100) + (third * 10) + fourth;
	
	printf("Decrypted number is %d\n", decrypted);
	return 0; 
} 

