#include <stdio.h>
int main(){
	int total,counter,grade,;
	float average;
	total=0;
	counter=0;  /*ע��counter��ʼֵΪ�㣬��Ϊ��������-1ʵ���϶�counter��һ��*/ 
	
	printf("Input grade,-1 to end:");
	scanf("%d",&grade);
	
	while(grade!=-1){
		total=total+grade;
		counter=counter+1;
		printf("Input grade,-1 to end:");
		scanf("%d",&grade);
	}
	
	
	if(counter!=0){
		average=(float)total/counter;  /*ǿ������ת���������float�������Ĳ�����total����һ�������������͵���ʱ����*/ 
		printf("Class average is %.2f\n%d",average,counter);  /*.2f��ʾ����������ʾ�����Ǿ�ȷ��С���������λ*/ 
	}                                               /*ֻ��printf�����ĸ�ʽת���в��ܹ��涨���ȣ�scanf��������*/   
	else{
		printf("No grade were input\n%d",counter);
	}
	return 0;
}
