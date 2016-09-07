#include <stdio.h>
int main() {
	int light_num;
	int temp;
	scanf("%d%d", &light_num, &temp);
	int i, j;
	int k = 0, n = 0;//k为记号，即当达到temp的值时，熄灭灯 
	int light[1000] = {0};
	for(i = 0; n < light_num; i++) {
		if(i == light_num) {
			i = 0;//即是当一次循环后把i重置为0 
		}
		if(light[i] == 0) {//灯亮着，熄灭的灯不计数 
			k++;
		}
		if(k == temp) {
			k = 0;//k重置为0 
			n++;//记录已经熄灭的灯的数量 
			light[i] = 1;//灯熄灭 
			printf("%d\n", i + 1);
		}
	}
	return 0;
}
//输入13 5
//输出5 10 2 8 1 9 4 13 12 3 7 11 6 
