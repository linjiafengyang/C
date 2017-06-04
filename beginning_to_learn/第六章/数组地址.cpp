#include <stdio.h>
int main() {
	int array[5];
	printf("array = %p\n&array[0] = %p\n&array = %p", array, &array[0], &array);// %p 专门用来打印地址 
	return 0;
}
