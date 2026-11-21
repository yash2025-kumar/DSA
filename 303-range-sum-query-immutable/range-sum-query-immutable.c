


#include <stdlib.h>

typedef struct {
    int* prefix;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = numsSize;
    // Allocate size + 1 to avoid boundary checks when left == 0
    obj->prefix = (int*)calloc(numsSize + 1, sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }
    
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj) {
    if (obj) {
        free(obj->prefix);
        free(obj);
    }
}
