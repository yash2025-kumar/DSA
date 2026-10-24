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
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = result[1] = -1;
    int first = -1, last = -1, minGap = INT_MAX;
    int index = 1;
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;
    while(cur->next) {
        int a = prev->val, b = cur->val, c = cur->next->val;
        if((b > a && b > c) || (b < a && b < c)) {
            if(first == -1) first = index;
            else if(index - last < minGap) minGap = index - last;
            last = index;
        }
        prev = cur;
        cur = cur->next;
        index++;
    } 
    if(minGap != INT_MAX) {
        result[0] = minGap;
        result[1] = last - first;
    }
    return result;
}