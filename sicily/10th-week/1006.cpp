int countLetters(const char * const str) {
    int len = 0;
    int i;
    for(i = 0; str[i] != 0; i++) {
        if(str[i] >= 65 && str[i] <= 122) {
            len++;
        }
    }
    return len;
}
