


#include <stdlib.h>

#define SIZE 10007

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
    struct Node *hnext;
} Node;

typedef struct {
    int capacity, size;
    Node *head, *tail;
    Node *table[SIZE];
} LRUCache;

int hashKey(int key) {
    return (unsigned int)key % SIZE;
}

Node* newNode(int key, int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->prev = n->next = n->hnext = NULL;
    return n;
}

void removeList(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
}

void addFront(LRUCache* obj, Node* n) {
    n->prev = obj->head;
    n->next = obj->head->next;
    obj->head->next->prev = n;
    obj->head->next = n;
}

Node* findNode(LRUCache* obj, int key) {
    Node* n = obj->table[hashKey(key)];
    while (n != NULL && n->key != key)
        n = n->hnext;
    return n;
}

void removeHash(LRUCache* obj, Node* n) {
    int h = hashKey(n->key);
    Node** p = &obj->table[h];

    while (*p != NULL && *p != n)
        p = &(*p)->hnext;

    if (*p == n)
        *p = n->hnext;
}

void addHash(LRUCache* obj, Node* n) {
    int h = hashKey(n->key);
    n->hnext = obj->table[h];
    obj->table[h] = n;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)calloc(1, sizeof(LRUCache));
    obj->capacity = capacity;
    obj->head = newNode(0, 0);
    obj->tail = newNode(0, 0);

    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* n = findNode(obj, key);

    if (n == NULL)
        return -1;

    removeList(n);
    addFront(obj, n);
    return n->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* n = findNode(obj, key);

    if (n != NULL) {
        n->value = value;
        removeList(n);
        addFront(obj, n);
        return;
    }

    if (obj->capacity == 0)
        return;

    if (obj->size == obj->capacity) {
        Node* lru = obj->tail->prev;
        removeList(lru);
        removeHash(obj, lru);
        free(lru);
        obj->size--;
    }

    n = newNode(key, value);
    addFront(obj, n);
    addHash(obj, n);
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    Node* n = obj->head;

    while (n != NULL) {
        Node* next = n->next;
        free(n);
        n = next;
    }

    free(obj);
}
