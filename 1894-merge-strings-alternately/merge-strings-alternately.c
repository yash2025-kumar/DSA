char * mergeAlternately(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    char *res = malloc(m+n+1);
    int i = 0, j = 0, k = 0;
    while(i < m || j < n) {
        if(i < m) {
            res[k] = word1[i];
            i++;
            k++;
        }
        if(j < n) {
            res[k] = word2[j];
            j++;
            k++;
        }
    }
    res[k] = '\0';
    return res;
}

