#include<stdio.h>

int main()
{
int i,j,t,k,s;
printf("Following are palindrome primes not greater than 1000: ");
for(i=0;i<=9;++i) //��ٵ�һλ
for(j=0;j<=9;++j) //��ٵڶ�λ
for(k=0;k<=9;++k) //��ٵ���λ
{
s=i*100 + j*10 + k; //������ɵ�����
t=k*100 + j*10 + i; //�����Ӧ�ķ�����
if(i == 0 && j==0) //����������ǰ��λΪ0�����
{
t/100;
}
else if(i ==0) //���������ĵ�һλΪ0�����
{
t/10;
}
if(s>10 && s==t ) //������10��Ϊ���������������
{
printf("%d	",s);
}
}
return 0;
}

//�жϲ���n�Ƿ�Ϊ����
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
