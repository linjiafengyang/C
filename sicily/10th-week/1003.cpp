int smallestElement(int * array, int size) {
    int smallest, i;
    smallest = array[0];
    for(i = 0; i < size; i++) {
        if(array[i] < smallest) {
            smallest = array[i];
        }
    }
    return smallest;
}
