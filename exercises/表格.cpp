#include <stdio.h>
int main(){
int i,j;
for(i=1;i<=9;i++){ 
    for(j=1;j<=i;j++) //先输出框行
    printf("+------");
    printf("+\n");
    for(j=1;j<=i;j++) //再输出数据行
    printf("|%d*%d=%2d",j,i,i*j);
    printf("|\n");
}
printf("+------+------+------+------+------+------+------+------+------+\n");

return 0;
}