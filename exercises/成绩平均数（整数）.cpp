#include <stdio.h>
int main(){
	int total,counter,grade,average;
	total=0;
	counter=0;
	
	printf("Input grade,-1 to end:");
	scanf("%d",&grade);
	
	while(grade!=-1){
		total=total+grade;
		counter=counter+1;
		printf("Input grade,-1 to end:");
		scanf("%d",&grade);
	}
	
	if(counter!=0){
		average=total/counter;
		printf("Class average is %d\n",average);
	}
	else{
		printf("No grade were input\n");
	}
	return 0;
}
