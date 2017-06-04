#include <stdio.h>
#include <string.h>
#include <time.h> 
int main(){
	clock_t start, end;
    start = clock();
    
	char string[5];
	char*str1="********************";
	strcpy(string,str1);/*拷贝字符串到另一个*/ 
	printf("%s\n\n",string);
	
	char destination[25];
	char*blank="",*c="c++",*Borland="Borland";
	strcpy(destination,Borland);
	strcat(destination,blank);
	strcat(destination,c);/*字符串拼接*/ 
	printf("%s\n\n",destination);
	
	char*buf1="aaa",*buf2="bbb";
	int ptr;
	ptr=strcmp(buf2,buf1);/*串比较*/ 
	if(ptr>0){
		printf("Buffer2 is greater than Buffer1\n\n");
	}
	else{
		printf("Buffer2 is less than Buffer1\n\n");
	}
	
	char*buf3="BBB",*buf4="bbb";
	int ptr1;
	ptr1=strnicmp(buf4,buf3,5);/*将一个串中的一部分与另一个串比较，不管大小写*/ 
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
	i=strlen(it);/*求字符串的长度*/ 
	printf("The length of the string is %d\n\n",i);
	
	char*string1="1234567890";
	char*string2="747DC8";
	int length;
	length=strcspn(string1,string2);/*在串中查找第一个给定字符集内容的段*/ 
	printf("Character where strings intersect is at position %d\n\n",length);
	
	char string3[]="abcdefghijklmnopqrstuvwxyz",*ptr2;
	ptr2=strupr(string3);/*将串中的小写字母转换为大写字母*/ 
	printf("%s\n\n",ptr2);
	
	char input[16]="abc,d";
	char*p;
	p=strtok(input,",");/*查找由在第二个串中指定的分界符分隔开的单词*/ 
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
