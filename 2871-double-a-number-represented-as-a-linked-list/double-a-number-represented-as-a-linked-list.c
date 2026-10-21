/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* doubleIt(struct ListNode* head) {
    head = reverse(head);
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    int carry = 0;

    while(curr != NULL) {
        int sum = curr->val * 2 + carry;
        curr->val = sum % 10;
        carry = sum / 10;
        prev = curr;
        curr = curr->next;
    }

    if(carry) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = carry;
        node->next = NULL;
        prev->next = node;
    }

    return reverse(head);
}