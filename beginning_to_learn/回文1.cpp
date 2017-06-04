#include<stdio.h>

int main()
{
int i,j,t,k,s;
printf("Following are palindrome primes not greater than 1000: ");
for(i=0;i<=9;++i) //穷举第一位
for(j=0;j<=9;++j) //穷举第二位
for(k=0;k<=9;++k) //穷举第三位
{
s=i*100 + j*10 + k; //计算组成的整数
t=k*100 + j*10 + i; //计算对应的反序数
if(i == 0 && j==0) //处理整数的前两位为0的情况
{
t/100;
}
else if(i ==0) //处理整数的第一位为0的情况
{
t/10;
}
if(s>10 && s==t ) //若大于10且为回文素数，则输出
{
printf("%d	",s);
}
}
return 0;
}

//判断参数n是否为素数
int a(int n)
{
int i;
for(i=2;i<(n-1)/2;i++)
{
if(n%i == 0)
return 0;
}

return 1;

}
