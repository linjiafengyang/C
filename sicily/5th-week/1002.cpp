#include <stdio.h>
int main() {
    int n;
    int i;
    int grade;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &grade);
        if((grade >= 0) && (grade <= 100)){
            switch(grade / 10){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            	printf("E\n");
            	break;
            case 6:
            	printf("D\n");
            	break;
            case 7:
            	printf("C\n");
            	break;
            case 8:
            	printf("B\n");
            	break;
            case 9:
            case 10:
            	printf("A\n");
            	break;
            default:
            	printf("error\n");
            	break;
            }
        }
        else {
            printf("error\n");
        }
    }
    return 0;
}
