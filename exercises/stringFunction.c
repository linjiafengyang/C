#include <stdio.h>
#include <string.h>
#include <time.h> 
int main(){
	clock_t start, end;
    start = clock();
    
	char string[5];
	char*str1="********************";
	strcpy(string,str1);/*�����ַ�������һ��*/ 
	printf("%s\n\n",string);
	
	char destination[25];
	char*blank="",*c="c++",*Borland="Borland";
	strcpy(destination,Borland);
	strcat(destination,blank);
	strcat(destination,c);/*�ַ���ƴ��*/ 
	printf("%s\n\n",destination);
	
	char*buf1="aaa",*buf2="bbb";
	int ptr;
	ptr=strcmp(buf2,buf1);/*���Ƚ�*/ 
	if(ptr>0){
		printf("Buffer2 is greater than Buffer1\n\n");
	}
	else{
		printf("Buffer2 is less than Buffer1\n\n");
	}
	
	char*buf3="BBB",*buf4="bbb";
	int ptr1;
	ptr1=strnicmp(buf4,buf3,5);/*��һ�����е�һ��������һ�����Ƚϣ����ܴ�Сд*/ 
	if(ptr1>0){
		printf("Buffer4 is greater than Buffer3\n\n");
	} 
	if(ptr1<0){
		printf("Buffer4 is less than Buffer3\n\n");
	}
	if(ptr1==0){
		printf("Buffer4 is equal to Buffer3\n\n");
	}
	
	int i=0;
	char*it="Hello world!";
	i=strlen(it);/*���ַ����ĳ���*/ 
	printf("The length of the string is %d\n\n",i);
	
	char*string1="1234567890";
	char*string2="747DC8";
	int length;
	length=strcspn(string1,string2);/*�ڴ��в��ҵ�һ�������ַ������ݵĶ�*/ 
	printf("Character where strings intersect is at position %d\n\n",length);
	
	char string3[]="abcdefghijklmnopqrstuvwxyz",*ptr2;
	ptr2=strupr(string3);/*�����е�Сд��ĸת��Ϊ��д��ĸ*/ 
	printf("%s\n\n",ptr2);
	
	char input[16]="abc,d";
	char*p;
	p=strtok(input,",");/*�������ڵڶ�������ָ���ķֽ���ָ����ĵ���*/ 
	if(p){
		printf("%s\n",p);
	}
	p=strtok(NULL,",");
	if(p){
		printf("%s\n\n",p);
	}
	
	end = clock();
    printf("The time was: %lf\n", (end - start) / CLK_TCK);
	return 0;
}
