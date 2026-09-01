bool isPalindrome(char* word) {
    int length = strlen(word);
    int l = 0, h = length - 1;
    while(l < h) {
        if(word[l] != word[h]) {
            return false;
        }
        l++;
        h--;
    }
    return true;
}
char* firstPalindrome(char** words, int wordsSize) {
    for(int i=0; i<wordsSize; i++) {
        if(isPalindrome(words[i])) {
            return words[i];
        }
    }
    return "";
}   
    