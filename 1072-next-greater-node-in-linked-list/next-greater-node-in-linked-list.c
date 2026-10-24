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
int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int n = 0;
    for(struct ListNode* p = head; p; p = p->next) {
        n++;
    }
    int* vals = malloc(n * sizeof(int));
    int i = 0;
    for(struct ListNode* p = head; p; p = p->next) {
        vals[i++] = p->val;
    }
    int* answer = calloc(n, sizeof(int));
    int* stack = malloc(n * sizeof(int));
    int top = 0;
    for(int i=0; i<n; i++) {
        while(top > 0 && vals[stack[top - 1]] < vals[i]) {
            answer[stack[--top]] = vals[i];
        }
        stack[top++] = i;
    }
    free(vals);
    free(stack);
    *returnSize = n;
    return answer;
}