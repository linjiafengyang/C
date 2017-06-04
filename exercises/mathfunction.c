#include <time.h>
#include <stdio.h>
#include <math.h>

int main(void){
	
    clock_t start, end;
    start = clock();
   
    float abs;
	int num=-123;
    abs=fabs(num);  /*fabs求实数型的绝对值 */ 
	printf("number:%d  absolute value:%f\n\n\n",num,abs);
	
	
	
	double value;
    double x = 4;
   /* ldexp raises 2 by a power of 3
      then multiplies the result by 4   */
    value = ldexp(x,3);
    printf("The ldexp value is: %lf\n\n\n",value);  /*输出的value=2^3*4  */
	
	
	
	double a,b,c,d,e,f,g,h,i,j;
	b=10;
	a=log10(b);/*以十为底的对数*/ 
	c=pow(b,a);/*求b^a的值*/ 
	d=sqrt(b*b);/*开方*/ 
	e=ceil(sqrt(b));/* 取整，比x大的最小整数*/ 
	f=floor(sqrt(b));/*取整，比x小的最大整数*/ 
	g=fmod(a,b);/*返回两参数相除的余数*/ 
	h=hypot(b,b);/* 已知直角三角形两个直角边长度，求斜边长度*/ 
	i=sinf(a);/*正弦*/ 
	j=asinf(a);/* 反正弦*/ 
	
	printf("%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n\n\n",a,c,d,e,f,g,h,i,j); 
    

	
    end = clock();
    printf("The time was: %lf\n", (end - start) / CLK_TCK);
    return 0;
}
