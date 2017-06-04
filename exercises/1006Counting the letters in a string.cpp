int countLetters(const char * const str) {
	int len = 0;
	int i;
	for(i = 0; str[i] != 0; i++) {
		if(str[i] >= 65 && str[i] <= 122) {//65表示字母 a，122表示字母 z 
			len++;
		}
	}
	return len;
}
