bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize < 2) return false;
    int size = 1;
    while(size < numsSize * 2) size <<= 1;
    int mask = size - 1;

    int* table = (int*)malloc(size* sizeof(int));
    bool* used = (bool*)calloc(size, sizeof(bool));

    bool found = false;
    for(int i=0; i<numsSize; i++) {
        int x = nums[i];
        unsigned int h = ((unsigned int)x * 2654435761u) & mask;

        while(used[h]) {
            if(table[h] == x) {
                found = true;
                goto done;
            }
            h = (h+1) & mask;
        }
        used[h] = true;
        table[h] = x;
    }
    done:
        free(table);
        free(used);
        return found;
}