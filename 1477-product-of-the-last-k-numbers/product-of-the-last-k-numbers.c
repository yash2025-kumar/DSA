#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *prefix;
    int size;
    int capacity;
} ProductOfNumbers;

ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers *obj = (ProductOfNumbers *)malloc(sizeof(ProductOfNumbers));
    obj->capacity = 16;
    obj->prefix = (int *)malloc(sizeof(int) * obj->capacity);
    obj->prefix[0] = 1;
    obj->size = 1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers *obj, int num) {
    if (num == 0) {
        obj->size = 1;
        obj->prefix[0] = 1;
        return;
    }

    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        int *newPrefix = (int *)realloc(obj->prefix, sizeof(int) * obj->capacity);
        if (newPrefix != NULL) {
            obj->prefix = newPrefix;
        }
    }

    obj->prefix[obj->size] = obj->prefix[obj->size - 1] * num;
    obj->size++;
}

int productOfNumbersGetProduct(ProductOfNumbers *obj, int k) {
    if (k >= obj->size) {
        return 0;
    }
    int last = obj->prefix[obj->size - 1];
    int prev = obj->prefix[obj->size - 1 - k];
    return last / prev;
}

void productOfNumbersFree(ProductOfNumbers *obj) {
    if (obj != NULL) {
        free(obj->prefix);
        free(obj);
    }
}



