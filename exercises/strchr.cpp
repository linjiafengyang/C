#include<stdio.h>
#include<string.h>
int main(){
	char string[15];
	char*ptr,c='r';
	strcpy(string,"This is a string");
	ptr=strchr(string,c);/*��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮��*/ 
	if(ptr){
		printf("The character %c is at position:%d\n\n",c,ptr-string);
	}
	else{
		printf("The character was not found\n\n");
	}
	return 0;
}
