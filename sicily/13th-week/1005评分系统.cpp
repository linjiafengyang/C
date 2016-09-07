#include <stdio.h>
int main() {
    int n;
    float average;
    int a[101];
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    int i, total = 0;
    scanf("%d", &n);
    if(n >= 3 && n <= 101){
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            total = total + a[i];
            if(a[i] >= 0 && a[i] < 60) {
                count1++;
            }
            else if(a[i] >= 60 && a[i] < 75) {
                count2++;
            }
            else if(a[i] >= 75 && a[i] < 85) {
                count3++;
            }
            else if(a[i] >= 85 && a[i] < 95) {
                count4++;
            }
            else {
                if(a[i] >= 95 && a[i] <= 100)
                    count5++;
            }
        }
        int largest = a[0];
        int smallest = a[0];
        for(i = 0; i < n; i++) {
            if(largest < a[i]) {
                largest = a[i];
            }
            if(smallest > a[i]) {
                smallest = a[i];
            }
        }
        average = (float)(total - largest - smallest) / (n - 2);
        printf("%.2f\n", average);
        printf("%d\n%d\n%d\n%d\n%d\n", count1, count2, count3, count4, count5);
    }
    return 0;
}                                 
