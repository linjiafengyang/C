#include <stdio.h>
int main(){
	int total,counter,grade,;
	float average;
	total=0;
	counter=0;  /*注意counter初始值为零，因为后面输入-1实际上多counter了一次*/ 
	
	printf("Input grade,-1 to end:");
	scanf("%d",&grade);
	
	while(grade!=-1){
		total=total+grade;
		counter=counter+1;
		printf("Input grade,-1 to end:");
		scanf("%d",&grade);
	}
	
	
	if(counter!=0){
		average=(float)total/counter;  /*强制类型转换运算符（float）将它的操作数total产生一个浮点数据类型的临时副本*/ 
		printf("Class average is %.2f\n%d",average,counter);  /*.2f表示浮点数的显示精度是精确到小数点后面两位*/ 
	}                                               /*只有printf（）的格式转换中才能够规定精度，scanf（）不行*/   
	else{
		printf("No grade were input\n%d",counter);
	}
	return 0;
}
