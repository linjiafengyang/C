#include <stdio.h>
int money_50(float money);
int money_20(float money);
int money_10(float money);
int money_5(float money);
int money_1(float money);
int money_05(float money);
int money_01(float money);
int main() {
    float n;
    int sum;
    while(scanf("%f", &n) != EOF) {
        int i;
        sum = 0;
        float money = n;
        sum = money_50(money);
        printf("%d\n", sum);
    }
}
int money_50(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 50) {
        while(temp >= 50) {
            temp = temp - 50;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_20(money - j * 50);
        }
    }
    else {
        sum = money_20(money);
    }
    return sum;
}
int money_20(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 20) {
        while(temp >= 20) {
            temp = temp - 20;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_10(money - j * 20);
        }
    }
    else {
        sum = money_10(money);
    }
    return sum;
}
int money_10(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 10) {
        while(temp >= 10) {
            temp = temp - 10;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_5(money - j * 10);
        }
    }
    else {
        sum = money_5(money);
    }
    return sum;
}
int money_5(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 5) {
        while(temp >= 5) {
            temp = temp - 5;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_1(money - j * 5);
        }
    }
    else {
        sum = money_1(money);
    }
    return sum;
}
int money_1(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 1) {
        while(temp >= 1) {
            temp = temp - 1;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_05(money - j * 1);
        }
    }
    else {
        sum = money_05(money);
    }
    return sum;
}
int money_05(float money) {
    int i = 0;
    int j;
    int sum = 0;
    float temp = money;
    if(temp >= 0.5) {
        while(temp >= 0.5) {
            temp = temp - 0.5;
            i++;
        }
        for(j = 0; j <= i; j++) {
            sum = sum + money_01(money - j * 0.5);
        }
    }
    else {
        sum = money_01(money);
    }
    return sum;
}
int money_01(float money) {
    int i = 0;
    return 1;
}
