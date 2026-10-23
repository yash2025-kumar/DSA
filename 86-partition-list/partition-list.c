/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* createNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* small = createNode(0);
    struct ListNode* large = createNode(0);;
    struct ListNode* smallP = small;
    struct ListNode* largeP = large;

    while(head != NULL) {
        if(head->val < x) {
            smallP->next = head;
            smallP = smallP->next;
            head = head->next;
        }
        else {
            largeP->next = head;
            largeP = largeP->next;
            head = head->next;
        }
        largeP->next = NULL;
        smallP->next = large->next;
    }
    return small->next;
}