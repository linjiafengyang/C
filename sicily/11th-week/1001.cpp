char a[1000];
char * sortString(const char * const s) {
    int i = 0;
    int j, k, temp;
    do {
        a[i] = s[i];
        i++;
    } while(s[i] != '\0');
    a[i] = '\0';
    int m = i - 1;
    for(j = 0; j < m; j++) {
        for(k = 0; k < m - j; k++) {
            if(a[k] > a[k + 1]) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
    return a;
}
void sortString(const char * const s, char * s1) {
    int i = 0;
    int j, k, temp;
    do {
        s1[i] = s[i];
        i++;
    } while(s[i] != '\0');
    s1[i] = '\0';
    int m = i - 1;
    for(j = 0; j < m; j++) {
        for(k = 0; k < m - j; k++) {
            if(s1[k] > s1[k + 1]) {
                temp = s1[k];
                s1[k] = s1[k + 1];
                s1[k + 1] = temp;
            }
        }
    }
}
