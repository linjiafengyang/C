int smallestElement(int * array, int size) {
	int i, j, temp;
	for(i = 1; i < size; i++) {
		for(j = 0; j < size - i; j++) {
			if(array[j] > array[j + 1]){
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
	return array[0];
}
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
