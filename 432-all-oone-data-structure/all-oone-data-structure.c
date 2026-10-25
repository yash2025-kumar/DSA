


#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100003
#define KEY_SIZE 11

typedef struct KeyNode {
    char key[KEY_SIZE];
    struct KeyNode *next;
} KeyNode;

typedef struct Bucket {
    int count;
    KeyNode *keys;
    struct Bucket *prev;
    struct Bucket *next;
} Bucket;

typedef struct HashEntry {
    char key[KEY_SIZE];
    Bucket *bucket;
    struct HashEntry *next;
} HashEntry;

typedef struct {
    Bucket *head;
    Bucket *tail;
    HashEntry *table[TABLE_SIZE];
} AllOne;

static unsigned int hashKey(const char *s) {
    unsigned int h = 0;
    while (*s)
        h = (h * 31 + (unsigned char)*s++) % TABLE_SIZE;
    return h;
}

static HashEntry *findEntry(AllOne *obj, const char *key) {
    unsigned int h = hashKey(key);
    HashEntry *e = obj->table[h];

    while (e) {
        if (strcmp(e->key, key) == 0)
            return e;
        e = e->next;
    }
    return NULL;
}

static void setEntry(AllOne *obj, const char *key, Bucket *b) {
    HashEntry *e = findEntry(obj, key);

    if (e) {
        e->bucket = b;
        return;
    }

    unsigned int h = hashKey(key);
    e = malloc(sizeof(HashEntry));
    strcpy(e->key, key);
    e->bucket = b;
    e->next = obj->table[h];
    obj->table[h] = e;
}

static void deleteEntry(AllOne *obj, const char *key) {
    unsigned int h = hashKey(key);
    HashEntry **p = &obj->table[h];

    while (*p) {
        if (strcmp((*p)->key, key) == 0) {
            HashEntry *tmp = *p;
            *p = tmp->next;
            free(tmp);
            return;
        }
        p = &(*p)->next;
    }
}

static Bucket *newBucket(int count) {
    Bucket *b = malloc(sizeof(Bucket));
    b->count = count;
    b->keys = NULL;
    b->prev = NULL;
    b->next = NULL;
    return b;
}

static void insertAfter(Bucket *pos, Bucket *b) {
    b->prev = pos;
    b->next = pos->next;
    pos->next->prev = b;
    pos->next = b;
}

static void removeBucket(Bucket *b) {
    b->prev->next = b->next;
    b->next->prev = b->prev;
    free(b);
}

static void addKey(Bucket *b, const char *key) {
    KeyNode *k = malloc(sizeof(KeyNode));
    strcpy(k->key, key);
    k->next = b->keys;
    b->keys = k;
}

static void removeKey(Bucket *b, const char *key) {
    KeyNode **p = &b->keys;

    while (*p) {
        if (strcmp((*p)->key, key) == 0) {
            KeyNode *tmp = *p;
            *p = tmp->next;
            free(tmp);
            return;
        }
        p = &(*p)->next;
    }
}

AllOne* allOneCreate() {
    AllOne *obj = calloc(1, sizeof(AllOne));

    obj->head = newBucket(0);
    obj->tail = newBucket(0);

    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;

    return obj;
}

void allOneInc(AllOne* obj, char* key) {
    HashEntry *e = findEntry(obj, key);
    Bucket *cur, *dest;

    if (!e) {
        cur = obj->head;

        if (cur->next != obj->tail && cur->next->count == 1)
            dest = cur->next;
        else {
            dest = newBucket(1);
            insertAfter(cur, dest);
        }

        addKey(dest, key);
        setEntry(obj, key, dest);
        return;
    }

    cur = e->bucket;

    if (cur->next != obj->tail &&
        cur->next->count == cur->count + 1)
        dest = cur->next;
    else {
        dest = newBucket(cur->count + 1);
        insertAfter(cur, dest);
    }

    addKey(dest, key);
    removeKey(cur, key);
    e->bucket = dest;

    if (!cur->keys)
        removeBucket(cur);
}

void allOneDec(AllOne* obj, char* key) {
    HashEntry *e = findEntry(obj, key);
    Bucket *cur = e->bucket;

    if (cur->count == 1) {
        removeKey(cur, key);
        deleteEntry(obj, key);

        if (!cur->keys)
            removeBucket(cur);

        return;
    }

    Bucket *dest;

    if (cur->prev != obj->head &&
        cur->prev->count == cur->count - 1)
        dest = cur->prev;
    else {
        dest = newBucket(cur->count - 1);
        insertAfter(cur->prev, dest);
    }

    addKey(dest, key);
    removeKey(cur, key);
    e->bucket = dest;

    if (!cur->keys)
        removeBucket(cur);
}

char* allOneGetMaxKey(AllOne* obj) {
    if (obj->tail->prev == obj->head)
        return "";

    return obj->tail->prev->keys->key;
}

char* allOneGetMinKey(AllOne* obj) {
    if (obj->head->next == obj->tail)
        return "";

    return obj->head->next->keys->key;
}

void allOneFree(AllOne* obj) {
    Bucket *b = obj->head;

    while (b) {
        Bucket *nextB = b->next;
        KeyNode *k = b->keys;

        while (k) {
            KeyNode *nextK = k->next;
            free(k);
            k = nextK;
        }

        free(b);
        b = nextB;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        HashEntry *e = obj->table[i];

        while (e) {
            HashEntry *nextE = e->next;
            free(e);
            e = nextE;
        }
    }

    free(obj);
}

/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char* param_3 = allOneGetMaxKey(obj);
 
 * char* param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/