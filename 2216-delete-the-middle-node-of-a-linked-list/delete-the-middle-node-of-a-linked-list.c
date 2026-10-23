/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head->next == NULL) {
        return NULL;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prevSlow = NULL;
    while(fast != NULL && fast->next != NULL) {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevSlow->next = slow->next;
    return head;
}
        