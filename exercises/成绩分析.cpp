#include <stdio.h>
int main(){
	int passes=0;
	int failures=0;
	int student=1;
	int result;
	
	
	while(student<=10){
		printf("Enter result(1=pass,2=fail):");
		scanf("%d",&result);
		
		if(result==1){
			passes=passes+1; /*可用先增一运算符++passes或者后增一passes++,下面failures，student同理*/ 
		}
	    else{
    		failures=failures+1;
    	}
    	student=student+1;
	}
	
	printf("Passed %d\n",passes);
	printf("Failed %d\n",failures);
	
	
	if(passes>8){
		printf("Raise tuition\n");
	}
	return 0;
}
