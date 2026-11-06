int heightChecker(int* heights, int heightsSize) {
    int freq[101] = {0};
    for(int i=0; i<heightsSize; i++) {
        freq[heights[i]]++;
    }
    int expected = 1;
    int count = 0;
    for(int i=0; i<heightsSize; i++) {
        while(freq[expected] == 0) {
            expected++;
        }
        if(heights[i] != expected) {
            count++;
        }
        freq[expected]--;
    }
    return count;
}