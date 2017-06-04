#include<stdio.h>
#include<string.h>
int main(){
	char string[15];
	char*ptr,c='r';
	strcpy(string,"This is a string");
	ptr=strchr(string,c);/*在一个串中查找给定字符的第一个匹配之处*/ 
	if(ptr){
		printf("The character %c is at position:%d\n\n",c,ptr-string);
	}
	else{
		printf("The character was not found\n\n");
	}
	return 0;
}
