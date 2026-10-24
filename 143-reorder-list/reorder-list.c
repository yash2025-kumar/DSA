/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while(head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void reorderList(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = reverse(slow->next);
    slow->next = NULL;
    struct ListNode* first = head;
    while(second) {
        struct ListNode* n1 = first->next;
        struct ListNode* n2 = second->next;
        first->next = second;
        second->next = n1;
        first = n1;
        second = n2;
    }
}