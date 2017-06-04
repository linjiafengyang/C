#include "stdio.h" 
 int main() 
 { 
 int num=0;
 int a[100]; 
 int i=0; 
 int m=0;
 int yushu; 
 char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 printf("请输入一个十进制整数："); 
 scanf("%d",&num); 
 while(num>0) 
 { 
 yushu=num%16; 
 a[i++]=yushu; 
 num=num/16; 

 } 
 printf("转化为十六进制的数为：0x"); 
 for(i=i-1;i>=0;i--)//倒序输出 
 { 
 m=a[i];
 printf("%c",hex[m]); 

 } 
 printf("\n"); 
 } 
