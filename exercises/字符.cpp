#include<stdio.h>
int main(void) {
    //����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
    char ch;//���߲���getchar�� ��scanf("%[^\n]", s);���Զ���ո񣬻س��ű�ʾ��������
    int char_num = 0,kongge_num = 0,int_num = 0,other_num = 0;
    while((ch = getchar()) != '\n') {//�س����������룬���һس���������
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
