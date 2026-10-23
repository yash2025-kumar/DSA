/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    struct ListNode* curr_odd = head;
    struct ListNode* curr_even = head->next;
    struct ListNode* first_even = curr_even;

    while(curr_even && curr_even->next) {
        curr_odd->next = curr_even->next;
        curr_odd = curr_odd->next;
        curr_even->next = curr_odd->next;
        curr_even = curr_even->next;
    }
    curr_odd->next = first_even;
    return head;
}