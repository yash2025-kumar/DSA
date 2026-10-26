



#include <stdlib.h>

#define SIZE 20011

typedef struct Node {
    int key, value, freq;
    struct Node *prev, *next;
    struct Node *hnext;
} Node;

typedef struct {
    Node *head, *tail;
} DList;

typedef struct {
    int capacity, size, minFreq;
    Node *table[SIZE];
    DList freqList[SIZE];
} LFUCache;

int hashKey(int key) {
    return (unsigned int)key % SIZE;
}

Node* createNode(int key, int value, int freq) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->freq = freq;
    n->prev = n->next = n->hnext = NULL;
    return n;
}

void initList(DList* list) {
    list->head = createNode(-1, 0, 0);
    list->tail = createNode(-1, 0, 0);
    list->head->next = list->tail;
    list->tail->prev = list->head;
}

void removeList(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
}

void addFront(DList* list, Node* n) {
    n->next = list->head->next;
    n->prev = list->head;
    list->head->next->prev = n;
    list->head->next = n;
}

int isEmpty(DList* list) {
    return list->head->next == list->tail;
}

void addHash(LFUCache* obj, Node* n) {
    int h = hashKey(n->key);
    n->hnext = obj->table[h];
    obj->table[h] = n;
}

Node* findNode(LFUCache* obj, int key) {
    Node* n = obj->table[hashKey(key)];

    while (n != NULL && n->key != key)
        n = n->hnext;

    return n;
}

void removeHash(LFUCache* obj, Node* n) {
    int h = hashKey(n->key);
    Node** p = &obj->table[h];

    while (*p != NULL && *p != n)
        p = &(*p)->hnext;

    if (*p == n)
        *p = n->hnext;
}

void increaseFreq(LFUCache* obj, Node* n) {
    int oldFreq = n->freq;

    removeList(n);

    if (oldFreq == obj->minFreq &&
        isEmpty(&obj->freqList[oldFreq])) {
        obj->minFreq++;
    }

    n->freq++;
    addFront(&obj->freqList[n->freq], n);
}

LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* obj = (LFUCache*)calloc(1, sizeof(LFUCache));

    obj->capacity = capacity;
    obj->size = 0;
    obj->minFreq = 0;

    for (int i = 0; i < SIZE; i++)
        initList(&obj->freqList[i]);

    return obj;
}

int lFUCacheGet(LFUCache* obj, int key) {
    Node* n = findNode(obj, key);

    if (n == NULL)
        return -1;

    int value = n->value;
    increaseFreq(obj, n);

    return value;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj->capacity == 0)
        return;

    Node* n = findNode(obj, key);

    if (n != NULL) {
        n->value = value;
        increaseFreq(obj, n);
        return;
    }

    if (obj->size == obj->capacity) {
        DList* list = &obj->freqList[obj->minFreq];
        Node* victim = list->tail->prev;

        removeList(victim);
        removeHash(obj, victim);
        free(victim);

        obj->size--;
    }

    n = createNode(key, value, 1);
    addHash(obj, n);
    addFront(&obj->freqList[1], n);

    obj->minFreq = 1;
    obj->size++;
}

void lFUCacheFree(LFUCache* obj) {
    if (obj == NULL)
        return;

    for (int i = 0; i < SIZE; i++) {
        Node* n = obj->freqList[i].head;

        while (n != NULL) {
            Node* next = n->next;
            free(n);
            n = next;
        }
    }

    free(obj);
}
