#include <stdio.h>
int main(){
	int passes = 0;
	int failures = 0;
	int student = 1;
	int result;
	while ( student <= 10 ){
		printf("Enter result (1=pass,2=fail):");
		scanf("%d",&result);
		while ( result != 1 && result != 2 ){
			printf("Invalid result\nEnter result (1=pass,2=fail):");
			scanf("%d",&result);
		}
		if ( result ==1 ){
			++passes;
		}
		else {
			++failures;
		}
		++student;
	}
	printf("Passed %d\nFailed %d\n",passes, failures);
	if( passes >= 8){
		printf("Raise tuition\n");
	}
	return 0;
} 

