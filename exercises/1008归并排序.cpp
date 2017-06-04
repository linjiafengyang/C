void merge(const int list1[], int size1, const int list2[], int size2, int list3[]) {
	int i = 0, h = 0, j = 0;
	while(j < size1 && h < size2) {
		if(list1[j] <= list2[h]) {
			list3[i] = list1[j];
			j++;
			i++;
		}
		else {
			list3[i] = list2[h];
			h++;
			i++;
		}
	}
	while(j < size1) {
		list3[i] = list1[j];
		j++;
		i++;
	}
	while(h < size2) {
		list3[i] = list2[h];
		h++;
		i++;
	}
}
