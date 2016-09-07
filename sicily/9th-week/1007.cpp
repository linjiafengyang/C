bool isSorted(const int list[], int size) {
    int i;
    for(i = 1; i < size; i++) {
        if(list[i - 1] > list[i]) {
            break;
        }
    }
    if(i == size) {
        return 1;
    } 
    else {
        return 0;
    }
}
