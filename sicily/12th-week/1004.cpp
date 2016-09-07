void selectionSort(double list[], int arraySize) {
    int i, j, min;
    double temp;
    for(i = 0; i < arraySize - 1; i++) {
        min = i;
        for(j = i + 1; j < arraySize; j++) {
            if(list[min] > list[j]) {
                min = j;
            }
        }
        if(min != i) {
            temp = list[min];
            list[min] = list[i];
            list[i] = temp;
        }
    }
}
