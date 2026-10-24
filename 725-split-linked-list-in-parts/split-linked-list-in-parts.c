/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    int n = 0;
    for(struct ListNode* p = head; p; p = p->next) {
        n++;
    }
    int base = n / k, extra = n % k;
    struct ListNode** parts = calloc(k, sizeof(struct ListNode*));
    struct ListNode* curr = head;
    for(int i=0; i<k  && curr; i++) {
        parts[i] = curr;
        int size = base + (i < extra ? 1 : 0);
        for(int j=1; j<size; j++) {
            curr = curr->next;
        }
        struct ListNode* next = curr->next;
        curr->next = NULL;
        curr = next;
    }
    *returnSize = k;
    return parts;
}