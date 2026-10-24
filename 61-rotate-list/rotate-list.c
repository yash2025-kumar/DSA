/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || !head->next) {
        return head;
    }
    int n = 1;
    struct ListNode* tail = head;
    while(tail->next) {
        tail = tail->next;
        n++;
    }
    k %= n;
    if(k == 0) {
        return head;
    }
    struct ListNode* newTail = head;
    for(int i=1; i<n-k; i++) {
        newTail = newTail->next;
    }
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}