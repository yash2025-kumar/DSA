



typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head;

    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;

    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* curr = obj->head;

        while (curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0)
        index = 0;

    if (index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* curr = obj->head;

    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = curr->next;
    curr->next = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
    } else {
        Node* curr = obj->head;

        for (int i = 0; i < index - 1; i++)
            curr = curr->next;

        temp = curr->next;
        curr->next = temp->next;
    }

    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;

    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    free(obj);
}




/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/