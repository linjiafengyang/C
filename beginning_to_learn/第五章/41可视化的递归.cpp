#include <stdio.h>
long factorial(long number);
void printRecursion(int n);
int main() {
	int i;
	for(i = 0; i <= 10; i++) {
		printf("%2d! = %ld\n", i, factorial(i));
	}
	return 0;
}
long factorial(long number) {
	if(number <= 1) {
		return 1;
	}
	else {
		printRecursion(number);
		return (number * factorial(number - 1));
	}
}
void printRecursion(int n) {
	printf("number = %*d\n", n, n);//%*d �е� * ��ʾ����������� n ����һ�� n ��ʾ��� 
}
