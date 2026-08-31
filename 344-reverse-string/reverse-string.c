void reverseString(char* s, int sSize) {
    int l = 0;
    int h = sSize - 1;
    while(l < h) {
        char temp = s[l];
        s[l] = s[h];
        s[h] = temp;
        l++;
        h--;
    }
}