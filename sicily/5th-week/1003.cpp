#include <stdio.h>
int main() {
    int num;
    int total;
    total = 0;
    while(num != -1) {
        scanf("%d", &num);
        switch(num) {
            case 1:
				total = total + 6;
				break;
            case 2:
				total = total + 8;
				break;
            case 3:
				total = total + 12;
				break;
            case 4:
				total = total + 3;
				break;
            case 5:
				total = total + 9;
				break;
            default:
				break;
        }
    }
    printf("%d", total);
    return 0;
}
