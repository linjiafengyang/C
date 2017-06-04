#include <stdio.h>
int main(){
	int radius;
	printf("Input the circle radius:");
	scanf("%d",&radius);
	printf("\nThe diameter is %d\n",2*radius);
	printf("The circumference is %f\n",2*3.14159*radius);
	printf("The area is %f\n",3.14159*radius*radius);
	return 0;
}
