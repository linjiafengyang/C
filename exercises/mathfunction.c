#include <time.h>
#include <stdio.h>
#include <math.h>

int main(void){
	
    clock_t start, end;
    start = clock();
   
    float abs;
	int num=-123;
    abs=fabs(num);  /*fabs��ʵ���͵ľ���ֵ */ 
	printf("number:%d  absolute value:%f\n\n\n",num,abs);
	
	
	
	double value;
    double x = 4;
   /* ldexp raises 2 by a power of 3
      then multiplies the result by 4   */
    value = ldexp(x,3);
    printf("The ldexp value is: %lf\n\n\n",value);  /*�����value=2^3*4  */
	
	
	
	double a,b,c,d,e,f,g,h,i,j;
	b=10;
	a=log10(b);/*��ʮΪ�׵Ķ���*/ 
	c=pow(b,a);/*��b^a��ֵ*/ 
	d=sqrt(b*b);/*����*/ 
	e=ceil(sqrt(b));/* ȡ������x�����С����*/ 
	f=floor(sqrt(b));/*ȡ������xС���������*/ 
	g=fmod(a,b);/*�������������������*/ 
	h=hypot(b,b);/* ��ֱ֪������������ֱ�Ǳ߳��ȣ���б�߳���*/ 
	i=sinf(a);/*����*/ 
	j=asinf(a);/* ������*/ 
	
	printf("%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n\n\n",a,c,d,e,f,g,h,i,j); 
    

	
    end = clock();
    printf("The time was: %lf\n", (end - start) / CLK_TCK);
    return 0;
}
