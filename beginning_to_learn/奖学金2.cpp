#define MAX 100
struct student  /*����ѧ�ṹ��*/
{ char name[20];
  int study_m;
  int class_m;
  char gan;
  char xi;
  int number;
};
#include<stdio.h>
#include<string.h>
main ()
{
struct student student[MAX];
int ss[MAX];
int n; int i,s;
int sum=0;
int A_sum=0;
printf("Please input the number of the students:");
scanf("%d",&n); /*����ѧ����*/
printf("\n");
printf("Please input the message of the student:\n");

for (i=1;i<=n;i++)
{
scanf("%s%d%d%s%s%d",student[i].name,&student[i].study_m,&student[i].class_m,&student[i].gan,&student[i].xi,&student[i].number); }

for(i=1;i<=n;i++)  /*��ÿ��ѧ���Ľ�ѧ�𣬴����Ӧ��ss[i] */
{  sum=0;
   if(student[i].study_m>80 && student[i].number>0)
   sum+=8000;
   if(student[i].study_m>85 && student[i].class_m>80)
   sum+=4000;
   if(student[i].study_m>90)
   sum+=2000;
   if(student[i].study_m>85 && student[i].xi=='Y')
   sum+=1000;
   if(student[i].class_m>80 && student[i].gan=='Y')
   sum+=850;
   ss[i]=sum;
   A_sum+=ss[i]; /*�ܽ�ѧ��*/
}
  sum=ss[1];s=1;
for(i=2;i<=n;i++)  /*����ཱѧ���ѧ��*/
  {
    if (sum<ss[i])
       { s=i;
  sum=ss[i];
  }
    }

printf("\n%s\n",student[s].name);
printf("%d\n",ss[s]);
printf("%d\n",A_sum);
}
