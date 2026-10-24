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

bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* second = reverse(slow->next);
    bool same = true;
    for(struct ListNode* a = head, *b = second; b; a = a->next, b = b->next) {
        if(a->val != b->val) {
            same = false;
            break;
        }
    }
    slow->next = reverse(second);
    return same;
}
        