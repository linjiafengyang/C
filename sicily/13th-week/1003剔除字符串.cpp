#include <stdio.h>
#include <string.h>
int main() {
	char str1[100], str2[100];
	int i, j;
	int len1, len2;
	scanf("%s%s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i = 0; i < len1; i++) {
		for(j = 0; j < len2; j++) {
			if(str1[i] == str2[j]) {
				str1[i] = ' ';
			}
		}
	}
	for(i = 0; i < len1; i++) {
		if(str1[i] != ' ') {
			printf("%c", str1[i]);
		}
	}
	printf("\n");
	return 0;
}
/*�ӵ�һ���ַ�����ɾ�������ڵڶ����ַ����г��ֵ��ַ�(������ĸ����㡢���ֵ������ַ�)�����ܸı������ַ���˳�����ִ�Сд�� �����п��Լ��������ַ����ĳ��ȶ�С��100���ַ���

���磺�����ַ����ֱ�Ϊ"a1b2c3hello123"��"123hello"���ѵڶ����ַ����г��ֵ��ַ�ȫ���޳�֮����Ϊ"abc"��
*/
