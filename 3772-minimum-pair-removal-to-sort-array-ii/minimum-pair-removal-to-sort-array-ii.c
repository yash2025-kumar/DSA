#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    ll sum;
    int left;
    int right;
} Pair;

typedef struct {
    Pair *data;
    int size;
    int capacity;
} MinHeap;

static bool smaller(Pair a, Pair b) {
    if (a.sum != b.sum)
        return a.sum < b.sum;
    return a.left < b.left;
}

static void push(MinHeap *h, Pair p) {
    if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = realloc(h->data, sizeof(Pair) * h->capacity);
    }

    int i = h->size++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (!smaller(p, h->data[parent]))
            break;

        h->data[i] = h->data[parent];
        i = parent;
    }

    h->data[i] = p;
}

static Pair pop(MinHeap *h) {
    Pair result = h->data[0];
    Pair last = h->data[--h->size];

    if (h->size > 0) {
        int i = 0;

        while (2 * i + 1 < h->size) {
            int child = 2 * i + 1;
            int right = child + 1;

            if (right < h->size &&
                smaller(h->data[right], h->data[child])) {
                child = right;
            }

            if (smaller(last, h->data[child]))
                break;

            h->data[i] = h->data[child];
            i = child;
        }

        h->data[i] = last;
    }

    return result;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int n = numsSize;

    if (n <= 1)
        return 0;

    ll *val = malloc(sizeof(ll) * n);
    int *prev = malloc(sizeof(int) * n);
    int *next = malloc(sizeof(int) * n);
    bool *alive = calloc(n, sizeof(bool));

    MinHeap heap;
    heap.size = 0;
    heap.capacity = 2 * n + 5;
    heap.data = malloc(sizeof(Pair) * heap.capacity);

    for (int i = 0; i < n; i++) {
        val[i] = nums[i];
        prev[i] = i - 1;
        next[i] = (i == n - 1) ? -1 : i + 1;
        alive[i] = true;
    }

    int bad = 0;

    for (int i = 0; i < n - 1; i++) {
        if (val[i] > val[i + 1])
            bad++;

        Pair p = {val[i] + val[i + 1], i, i + 1};
        push(&heap, p);
    }

    int operations = 0;

    while (bad > 0) {
        Pair p;

        while (1) {
            p = pop(&heap);

            int i = p.left;
            int j = p.right;

            if (alive[i] && alive[j] &&
                next[i] == j &&
                val[i] + val[j] == p.sum)
                break;
        }

        int i = p.left;
        int j = p.right;
        int l = prev[i];
        int r = next[j];

        if (l != -1 && val[l] > val[i])
            bad--;

        if (val[i] > val[j])
            bad--;

        if (r != -1 && val[j] > val[r])
            bad--;

        val[i] += val[j];
        alive[j] = false;

        next[i] = r;

        if (r != -1)
            prev[r] = i;

        if (l != -1 && val[l] > val[i])
            bad++;

        if (r != -1 && val[i] > val[r])
            bad++;

        if (l != -1) {
            Pair q = {val[l] + val[i], l, i};
            push(&heap, q);
        }

        if (r != -1) {
            Pair q = {val[i] + val[r], i, r};
            push(&heap, q);
        }

        operations++;
    }

    free(val);
    free(prev);
    free(next);
    free(alive);
    free(heap.data);

    return operations;
}