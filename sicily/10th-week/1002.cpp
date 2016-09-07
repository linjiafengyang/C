int newlist[1000];
int * doubleCapacity(int *list, int size) {
    int i;
    for(i = 0; i < size; i++) {
        newlist[i] = list[i];
    }
    for(; i < 2 * size; i++) {
        newlist[i] = 0;     
    }
    return newlist;
}
