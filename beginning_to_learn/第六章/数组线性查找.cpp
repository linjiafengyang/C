#include <stdio.h>
#define SIZE 100
int linearSearch(const int array[], int key, int size);
int main() {
	int a[SIZE];
	int i;
	int key;
	int temp;
	for(i = 0; i < 100; i++) {
		a[i] = 2 * i;
	}
	printf("Enter integer search key:\n");
	scanf("%d", &key);
	temp = linearSearch(a, key, SIZE);
	if(temp != -1) {
		printf("Found value in element %d\n", temp);
	}
	else {
		printf("Value not found\n");
	}
	return 0;
}
int linearSearch(const int array[], int key, int size) {
	int i;
	for(i = 0; i < size; ++i) {
		if(array[i] == key) {
			return i;
		}
	}
	return -1;
}
