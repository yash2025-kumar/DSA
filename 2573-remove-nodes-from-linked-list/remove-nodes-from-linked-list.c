
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL) {
        struct ListNode *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {
    head = reverse(head);

    int maxVal = head->val;
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;

    while (curr != NULL) {
        if (curr->val < maxVal) {
            prev->next = curr->next;
            curr = curr->next;
        } else {
            maxVal = curr->val;
            prev = curr;
            curr = curr->next;
        }
    }

    return reverse(head);
}
