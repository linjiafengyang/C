int indexOf(const char *s1, const char *s2) {
    int j, i, k, m;
    for(j = 0; *(s2 + j) != 0; j++) {
        if(*(s1 + 0) == *(s2 + j)) {
            k = 1;
            m = j + 1;
            while(*(s1 + k) == *(s2 + m) && *(s1 + k) != 0) {
                k++;
                m++;
            }
            if(*(s1 + k) == 0) {
                break;
            }
        }
    }
    if(*(s1 + k) == 0) {
        return j;
    }
    else {
        return -1;
    }
}
