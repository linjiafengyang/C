#include<stdio.h>
int day_p(int m){
    int i;
    switch(m){
        case(1):
        	i = 0;
        	break;
        case(2):
        	i = 31;
        	break;
        case(3):
        	i = 31 + 28;
        	break;
        case(4):
        	i = 31 + 28 + 31;
        	break;
        case(5):
        	i = 31 + 28 + 31 + 30;
        	break;
        case(6):
        	i = 31 + 28 + 31 + 30 + 31;
        	break;
        case(7):
        	i = 31 + 28 + 31 + 30 + 31 + 30;
        	break;
        case(8):
        	i = 31 + 28 + 31 + 30 + 31 + 30 + 31;
        	break;
        case(9):
        	i = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
        	break;
        case(10):
        	i = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        	break;
        case(11):
        	i = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        	break;
        case(12):
        	i = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        	break;
    } 
    return i;
}
int day_r(int m){
    int i;
    switch(m){
        case(1):
        	i = 0;
        	break;
        case(2):
        	i = 31;
        	break;
        case(3):
        	i = 31 + 29;
        	break;
        case(4):
        	i = 31 + 29 + 31;
        	break;
        case(5):
        	i = 31 + 29 + 31 + 30;
        	break;
        case(6):
        	i = 31 + 29 + 31 + 30 + 31;
        	break;
        case(7):
        	i = 31 + 29 + 31 + 30 + 31 + 30;
        	break;
        case(8):
        	i = 31 + 29 + 31 + 30 + 31 + 30 + 31;
        	break;
        case(9):
        	i = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31;
        break;
        case(10):
        	i = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
        	break;
        case(11):
        	i = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
        	break;
        case(12):
        	i = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
        	break;
    } 
    return i;
}
int mon(int m,int y){
    switch(m){
        case(1):
        printf("January %d\n", y);
        break;
        case(2):
        printf("February %d\n", y);
        break;
        case(3):
        printf("March %d\n", y);
        break;
        case(4):
        printf("April %d\n", y);
        break;
        case(5):
        printf("May %d\n", y);
        break;
        case(6):
        printf("June %d\n", y);
        break;
        case(7):
        printf("July %d\n", y);
        break;
        case(8):
        printf("August %d\n", y);
        break;
        case(9):
        printf("September %d\n", y);
        break;
        case(10):
        printf("October %d\n", y);
        break;
        case(11):
        printf("November %d\n", y);
        break;
        case(12):
        printf("December %d\n", y);
        break;
    }
}
main(){
    int y, m, d, k, n, i, j;
    scanf("%d%d%d", &y, &d, &m);
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        k = day_r(m);
        n = (d + k) % 7;
    }
    else{
        k = day_p(m);
        n = (d + k) % 7;
    }
    mon(m, y);
    printf("     Sun     Mon     Tue     Wed     Thu     Fri     Sat\n");
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        if(m == 2){
            for(j = 1; j <= 8 * n; j++){
                printf(" ");
            }
            for(i = 1; i <= 29; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }
            }
            if(i == 30 && n != 0){
                printf("\n");
            }
        }
        else if(m == 4 || m == 6 || m == 9 || m == 11){
            for(j = 1; j <= 8 * n; j++){
                printf(" ");
            }
            for(i = 1; i <= 30; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }
            }
            if(i == 31 && n != 0){
                printf("\n");
            }
        }
        else{
            for(j = 1; j <= 8 * n; j++){
                printf(" ");
            }
            for(i = 1; i <= 31; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }
            }
            if(i == 32 && n != 0){
                printf("\n");
            }
        }
    }
    else{
        if(m == 2){
            for(j = 1; j <= 8 * n; j++){
                printf(" ") ;
            }
            for(i = 1; i <= 28; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }
            }
            if(i == 29 && n != 0){
                printf("\n");
            }
        }
        else if(m == 4 || m == 6 || m == 9 || m == 11){
            for(j = 1; j <= 8 * n; j++){
                printf(" ");
            }
            for(i = 1; i <= 30; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }   
            }
            if(i == 31 && n != 0){
                printf("\n");
            }
        }
        else{
            for(j = 1; j <= 8 * n; j++){
                printf(" ");
            }
            for(i = 1; i <= 31; i++){
                if(n < 6){
                    printf("%8d", i);
                    n++;
                }
                else{
                    printf("%8d\n", i);
                    n = 0;
                }
            }
            if(i == 32 && n != 0){
                printf("\n");
            }
        }
    }
}
