



#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *url;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *current;
} BrowserHistory;

Node* createNode(char *url) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->url = (char *)malloc(strlen(url) + 1);
    strcpy(node->url, url);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory *obj =
        (BrowserHistory *)malloc(sizeof(BrowserHistory));

    obj->current = createNode(homepage);
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    Node *node = createNode(url);

    // Remove forward history
    Node *temp = obj->current->next;
    while (temp != NULL) {
        Node *nextNode = temp->next;
        free(temp->url);
        free(temp);
        temp = nextNode;
    }

    obj->current->next = node;
    node->prev = obj->current;
    obj->current = node;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps > 0 && obj->current->prev != NULL) {
        obj->current = obj->current->prev;
        steps--;
    }

    return obj->current->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps > 0 && obj->current->next != NULL) {
        obj->current = obj->current->next;
        steps--;
    }

    return obj->current->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    Node *temp = obj->current;

    // Move to the beginning
    while (temp->prev != NULL) {
        temp = temp->prev;
    }

    // Free the entire list
    while (temp != NULL) {
        Node *nextNode = temp->next;
        free(temp->url);
        free(temp);
        temp = nextNode;
    }

    free(obj);
}
