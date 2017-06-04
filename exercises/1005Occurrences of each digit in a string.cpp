int count1[10] = {0};
int * count(const char * const s){
	int i, j, t;
	char s_[100];
	for(i = 0; i < 10; i++) {
		count1[i] = 0;
	}
	for(i = 0; *(s + i) != 0; i++) {
		s_[i] = *(s + i);
	}
	s_[i] = 0;
	for(i = 0; *(s_ + i) != 0; i++) {
		t = *(s_ + i);
		if(t >= 48 && t <= 57) {
			count1[t - '0'] = 1;
			for(j = i + 1; *(s_ + j) != 0; j++) {
				if(*(s_ + j) == t) {
					count1[t - '0']++;
					s_[j] = 58;
				}
			}
		}
	}
	return count1;
}
