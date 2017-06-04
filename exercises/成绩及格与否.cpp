#include <stdio.h>
int main(){
	float grade;
	printf("Input a grade:");
	scanf("%f",&grade);
	printf("%s\n",grade>=60? "passed" :"failed");/*×¢Òâµ½%sºÍÃ°ºÅ*/ 
    return 0;
}
