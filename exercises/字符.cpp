#include<stdio.h>
int main(void) {
    //输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。
    char ch;//或者不用getchar， 用scanf("%[^\n]", s);可以读入空格，回车才表示结束输入
    int char_num = 0,kongge_num = 0,int_num = 0,other_num = 0;
    while((ch = getchar()) != '\n') {//回车键结束输入，并且回车符不计入
        if(ch >= 'a' && ch <= 'z' || ch <= 'Z' && ch >= 'A') {
            char_num++;
        }
        else if(ch == ' ') {
            kongge_num++;
        }
        else if(ch >= '0' && ch <= '9') {
            int_num++;
        }
        else {
            other_num++;
        }
    }
    printf("%d %d %d %d",char_num, int_num, kongge_num, other_num);
    return 0;
}
