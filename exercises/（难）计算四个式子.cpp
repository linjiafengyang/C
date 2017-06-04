#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c;
	double x,y;
	scanf("%d%d%d",&a,&b,&c);
	scanf("%lf%lf",&x,&y);
	double res1,res2,res3,res4;
	res1=1200/(24-4*5);
	
    res2=(a*a+b*b);
    res2=sqrt(res2);
    res2=c*res2;
    
    res3=log(log(pow(10,3.5)+2));
    
    res4=y+a*(int)(x+y)/2%4;   /*(int)表示强制转换，将（x+y）/2%4转换为整型*/
    
    printf("%.3lf\n%.3lf\n%.3lf\n%.3lf\n",res1,res2,res3,res4);
    return 0;
}
