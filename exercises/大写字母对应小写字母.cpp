#include <stdio.h> 
int main(){ 
   
	char a,b; 
   
	scanf("%c",&a); 
    
	b=a-('A'-'a'); /*��ֱ��b=a+32*/ 
    
	printf("%c\n",b); 
    
	return 0; 
}