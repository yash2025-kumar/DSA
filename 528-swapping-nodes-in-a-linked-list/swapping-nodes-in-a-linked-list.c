/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k) {
    struct ListNode* front = head;
    for(int i=1; i<k; i++) {
        front = front->next;
    }
    struct ListNode* back = head;
    struct ListNode* scout = front;
    while(scout->next) {
        scout = scout->next;
        back = back->next;
    }
    int temp = front->val;
    front->val = back->val;
    back->val = temp;
    return head;
}