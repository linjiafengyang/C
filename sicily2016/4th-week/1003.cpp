#include <iostream>
using namespace std;
int *sort(const int * const array, int size);
int *sort(const int * const array, int size){
    int *p = new int[size];
    int i, j;
    int temp;
    for(i = 0; i < size; i++){
        p[i] = array[i];
    }
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - 1 - i; j++){
            if(p[j] > p[j + 1]){
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    return p;
}
