/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    struct ListNode* last_sorted = head;
    struct ListNode* curr = head->next;

    while(curr != NULL) {
        if(last_sorted->val <= curr->val) {
            last_sorted = curr;
        }
        else {
            struct ListNode* prev = &dummy;
            while(prev->next->val < curr->val) {
                prev = prev->next;
            }
            last_sorted->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        curr = last_sorted->next;
    }
    return dummy.next;
}