/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* modify = head->next; // Points to where we write the sum
    struct ListNode* nextSum = modify;    // Traverses the list to calculate the sum

    while (nextSum != NULL) {
        int sum = 0;
        while (nextSum->val != 0) {
            sum += nextSum->val;
            nextSum = nextSum->next;
        }

        modify->val = sum;
        nextSum = nextSum->next; 
        modify->next = nextSum;  
        modify = modify->next;   
    }

    return head->next;
}
