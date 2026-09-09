/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode* curr = dummy;
    while(curr != NULL && curr->next != NULL) {
        if(curr->next->val == val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }
    return dummy->next;
}